#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"
#include "interface.h"
#include "dados.h"
#include "logica.h"
#include "listas.h"

/**
@file io.c
Funções que respondem a determinados comandos.
*/

/**
\brief Função que grava o estado atual do jogo num ficheiro que se chama "Ficheiro.txt".
 \param ficheiro Apontador para o ficheiro;
 \param e Estado.
*/
void grava(FILE *ficheiro,ESTADO *e) {
    ficheiro = fopen("ficheiro.txt", "w");
    mostrar_tabuleiro(e, ficheiro, 1);
    fprintf(ficheiro,"\n");
    movs(e, ficheiro, 1);
    fclose(ficheiro);
}


/**
\brief Função que transforma uma string em coordenada.
 \param coordenada String do tipo letra-numero.
 \returns Coordenada.
*/
COORDENADA str_to_coord (char *coordenada) {
    COORDENADA coord = {*coordenada - 'a', *(coordenada + 1) - '1'};
    return coord;
}


/**
\brief Função que lê o ficheiro criado e altera o estado do jogo.
 \param ficheiro apontador do ficheiro;
 \param estado Estado.
*/
void le(FILE *ficheiro,ESTADO *estado) {
    ficheiro = fopen("ficheiro.txt", "r");
    free(estado);
    estado = inicializar_estado();
/**
\brief Parte da função que lê o tabuleiro do ficheiro.
*/
    int num_jog;
    char jog1[BUF_SIZE], jog2[BUF_SIZE], linha[BUF_SIZE];

    for (int i = 0; fgets(linha, BUF_SIZE, ficheiro) != NULL && i < 8; i++)
        str_to_casa(linha, estado, i);
/**
\brief Parte da função que lê os movimentos do ficheiro.
*/
    for (int i = -1; fgets(linha, BUF_SIZE, ficheiro) != NULL; i++) {
        int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
        if (num_tokens == 3 || num_tokens == 2) {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = num_tokens==3 ? str_to_coord(jog2) : (COORDENADA) {-1, -1};
            armazena_jogada(c1, c2, i, estado);

            if (num_tokens==3) estado->num_jogadas++;
            estado->jogador_atual = num_tokens==3 ? 1:2;
            estado->ultima_jogada = num_tokens==3 ? c2:c1;
        }
    }
    fclose(ficheiro);
}


/**
\brief Função que imprime todas as jogadas anteriores.
 \param e Estado;
 \param stdout Apontador para o ficheiro;
 \param l Dá a opção de imprimir de uma forma (se é para o ficheiro criado, ou para a interface).
*/
void movs(ESTADO *e,FILE *stdout,int l) {
    int j = obter_numero_de_jogadas(e), i, linUm, colUm;
    if (l == 2) fprintf(stdout, "__| Jogador 1 | Jogador 2\n");

    for (i = 0; i < j; i++) {
        linUm = obter_x_jogada(e,i,1).linha + 1;
        colUm = obter_x_jogada(e,i,1).coluna + 97;
        int linDois = obter_x_jogada(e,i,2).linha + 1;
        int colDois = obter_x_jogada(e,i,2).coluna + 97;

        if (l == 1) fprintf(stdout, "%02d: %c%d %c%d\n", i + 1, colUm, linUm, colDois, linDois);
        else fprintf(stdout, "%02d|    %c%d     |    %c%d\n", i + 1, colUm, linUm, colDois, linDois);
    }
/**
\brief Se o jogador a jogar for o jogador 2, então significa que o jogador 1 já jogou.
*/
    if (obter_jogador_atual(e) == 2) {
        linUm = e->jogadas[j].jogador1.linha + 1;
        colUm = e->jogadas[j].jogador1.coluna + 97;

        if (l == 1) fprintf(stdout, "%02d: %c%d\n", i + 1, colUm, linUm);
        else {
            fprintf(stdout, "%02d|    %c%d\n", i + 1, colUm, linUm);
            fprintf(stdout, "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
        }
    }
}


/**
\brief Função que imprime todas as jogadas anteriores.
 \param e Estado;
 \param i Jogada para onde o jogador quer recuar.
*/
void pos(ESTADO *e,int i) {
    int itemp = i;

    while (itemp < obter_numero_de_jogadas(e)) {
        int linha1 = obter_x_jogada(e, itemp, 1).linha;
        int coluna1 = obter_x_jogada(e, itemp, 1).coluna;
        int linha2 = obter_x_jogada(e, itemp, 2).linha;
        int coluna2 = obter_x_jogada(e, itemp, 2).coluna;

        e->tab[7 - linha1][coluna1] = VAZIO;
        e->tab[7 - linha2][coluna2] = VAZIO;
        itemp++;
    }
    e->tab[7 - obter_x_jogada(e, itemp, 1).linha][obter_x_jogada(e, itemp, 1).coluna] = VAZIO;
    e->jogador_atual = 1;
    e->ultima_jogada = obter_x_jogada(e,i-1,2);
    e->tab[7 - obter_ultima_jogada(e).linha][obter_ultima_jogada(e).coluna] = BRANCA;
    e->num_jogadas = i;
}


/**
\brief Função que elimina as jogadas não possíveis
 \param l Lista de todas as jogadas;
 \param e Estado do jogo;
 \returns Uma lista com todas as jogadas possíveis.
*/
LISTA hipord(LISTA l,ESTADO *e) {
    LISTA r, sl, result;
    r = criar_lista();
    result = criar_lista();

    for (int i = 0; i < 2; i++) {
        r = insere_cabeca(r, devolve_cabeca(l));
        l = proximo(l);
    }

    sl = proximo(l);
    r = insere_cabeca(r, devolve_cabeca(sl));
    r = insere_cabeca(r, devolve_cabeca(l));
    sl = proximo(sl);

    for (; !(lista_esta_vazia(sl)); sl = proximo(sl))
        r = insere_cabeca(r, devolve_cabeca(sl));

    for (; !(lista_esta_vazia(r)); r = proximo(r)) {
        COORDENADA *coord;
        coord = (COORDENADA *) devolve_cabeca(r);
        if (coordenada_valida(*coord) && verifica_jogada(e, *coord))
            result = insere_cabeca(result, devolve_cabeca(r));
    }
    return result;
}


/**
\brief Função que joga pela vez do jogador. Heurística: Flood Fill.
 \param e Estado do jogo.
 \returns Um inteiro.
 */
int jog(ESTADO *e) {
    ESTADO etemp;
    etemp = *e;

    LISTA l = hipord(l_coord_adj(obter_ultima_jogada(e), obter_jogador_atual(e)), e);
    LISTA segundal = l;

    if (!ver_jogada(l, &etemp, e)) {
        int t = tamanho_lista(segundal);
        srand(time(NULL));
        int resultado = (rand() % t);
        for (; resultado > 0; resultado--, segundal = remove_cabeca(segundal));
        COORDENADA *coord;
        coord = (COORDENADA *) devolve_cabeca(segundal);
        jogar(e, *coord);
    }
    return 0;
}

void jog2(ESTADO *e) {
    ESTADO etemp;
    etemp = *e;

    LISTA l = l_coord_adj(obter_ultima_jogada(e),obter_jogador_atual(e));
    l = area_par_possivel(l, &etemp, e);

    int t = tamanho_lista(l);
    srand(time(NULL));

    int resultado = (rand() % t);
    for (; resultado > 1; resultado--, l = proximo(l));
    COORDENADA *coord;
    coord = (COORDENADA *) devolve_cabeca(l);
    jogar(e, *coord);


}