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
\brief Função que coloca altera o estado de cada casa de acordo com a char string recebida.
 \param linha Apontador para a string que é uma linha do tabuleiro;
 \param estado Estado;
 \param l Número da linha.
*/
void str_to_casa (char *linha, ESTADO *estado, int l) {
    int i = 0;
    while (i < 8) {
        if (linha[i] == '*') {
            estado->tab[l][i] = BRANCA;
            i++;
        } else if (linha[i] == '#') {
            estado->tab[l][i] = PRETA;
            i++;
        } else if (linha[i] == '1') {
            estado->tab[l][i] = UM;
            i++;
        } else if (linha[i] == '2') {
            estado->tab[l][i] = DOIS;
            i++;
        } else {
            estado->tab[l][i] = VAZIO;
            i++;
        }
    }
}


/**
\brief Função que armazena as duas coordenadas no array das jogadas no estado
 \param c1 Coordenada do jogador 1;
 \param c2 Coordenada do jogador 2;
 \param i Número da jogada;
 \param estado Estado.
*/
void armazena_jogada(COORDENADA c1, COORDENADA c2, int i, ESTADO *estado) {
    estado->jogadas[i].jogador1 = c1;
    estado->jogadas[i].jogador2 = c2;
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
    int i = 0;
    char jog1[BUF_SIZE];
    char jog2[BUF_SIZE];
    char linha[BUF_SIZE];

    while ((fgets(linha, BUF_SIZE, ficheiro) != NULL) && (i < 8)) {
        str_to_casa(linha, estado, i);
        i++;
    }

    i = 0;

/**
\brief Parte da função que lê os movimentos do ficheiro.
*/

    while (fgets(linha, BUF_SIZE, ficheiro) != NULL) {
        int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
        if (num_tokens == 3) {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = str_to_coord(jog2);
            armazena_jogada(c1, c2, i, estado);

            estado->num_jogadas++;
            estado->jogador_atual = 1;
            estado->ultima_jogada = c2;

            i++;

        } else {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = {-1, -1};
            armazena_jogada(c1, c2, i, estado);

            estado->jogador_atual = 2;
            estado->ultima_jogada = c1;
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
    int j = obter_numero_de_jogadas(e);
    int i;
    int ljum = 0, cjum = 0, ljdois = 0, cjdois = 0;

    if (l == 2) fprintf(stdout, "__| Jogador 1 | Jogador 2\n");


    for (i = 0; i < j; i++) {
        ljum = e->jogadas[i].jogador1.linha + 1;
        cjum = e->jogadas[i].jogador1.coluna + 97;
        ljdois = e->jogadas[i].jogador2.linha + 1;
        cjdois = e->jogadas[i].jogador2.coluna + 97;

        if (l == 1) fprintf(stdout, "%02d: %c%d %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
        else fprintf(stdout, "%02d|    %c%d     |    %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
    }

/**
\brief Se o jogador a jogar for o jogador 2, então significa que o jogador 1 já jogou.
*/
    if (obter_jogador_atual(e) == 2) {
        ljum = e->jogadas[j].jogador1.linha + 1;
        cjum = e->jogadas[j].jogador1.coluna + 97;


        if (l == 1) fprintf(stdout, "%02d: %c%d\n", i + 1, cjum, ljum);
        else {
            fprintf(stdout, "%02d|    %c%d\n", i + 1, cjum, ljum);
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
        int linha1 = e->jogadas[itemp].jogador1.linha;
        int coluna1 = e->jogadas[itemp].jogador1.coluna;
        int linha2 = e->jogadas[itemp].jogador2.linha;
        int coluna2 = e->jogadas[itemp].jogador2.coluna;

        e->tab[7 - linha1][coluna1] = VAZIO;
        e->tab[7 - linha2][coluna2] = VAZIO;
        itemp++;
    }
    e->tab[7 - e->jogadas[itemp].jogador1.linha][e->jogadas[itemp].jogador1.coluna] = VAZIO;
    e->jogador_atual = 1;
    e->ultima_jogada = e->jogadas[i - 1].jogador2;
    e->tab[7 - e->ultima_jogada.linha][e->ultima_jogada.coluna] = BRANCA;

    e->num_jogadas = i;
}


/**
\brief Função que verifica se, com a jogada feita, o jogo acaba.
 \param etemp Estado temporário que serve para testes;
 \param c Coordenada que é jogada.
*/
int verifica_fim_jog(ESTADO *etemp, ESTADO *e, COORDENADA c) {
    jogar(etemp, c);
    if (fim_jogo(etemp) != 3)
        return 1;
    *etemp=*e;
    return 0;
}

int compara_coord(COORDENADA c,COORDENADA d){
    if (c.linha==d.linha && c.coluna==d.coluna)
        return 1;
    return 0;
}

int ver_jogada(LISTA sl,ESTADO *etemp, ESTADO *e,COORDENADA h1,COORDENADA h2,COORDENADA h3,COORDENADA h4){
    COORDENADA *coord;
    coord = malloc(sizeof(COORDENADA));
    while(lista_esta_vazia(sl)==0){
        coord = (COORDENADA *) sl->valor;

        if (compara_coord(*coord,h1) || compara_coord(*coord,h2) || compara_coord(*coord,h3) || compara_coord(*coord,h4) || verifica_fim_jog(etemp, e, *coord) == 1) {
            jogar(e, *coord);
            return 1;
        } else sl=remove_cabeca(sl);
    }
    return 0;
}

/**
\brief Função que joga pela vez do jogador. Heurística: Flood Fill.
 \param e Estado do jogo.
*/
int jog(ESTADO *e) {
    COORDENADA c, *coord, h1, h2, h3, h4;

    c.linha = obter_ultima_jogada(e).linha;
    c.coluna = obter_ultima_jogada(e).coluna;
    int i = 1;
    if (obter_jogador_atual(e) == 2) i = -1;
    h1.coluna = c.coluna - i;
    h1.linha = c.linha - i;

    h2.coluna = c.coluna;
    h2.linha = c.linha - i;

    h3.coluna = c.coluna - i;
    h3.linha = c.linha;

    h4.coluna = c.coluna + i;
    h4.linha = c.linha - i;

    LISTA l = criar_lista();

    for (i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            COORDENADA *d;
            d = malloc(sizeof(COORDENADA));

            d->linha = c.linha + i;
            d->coluna = c.coluna + j;
            if (verifica_jogada(e, *d) == 1) {
                l = insere_cabeca(l, d);
            }
        }




    ESTADO *etemp;
    etemp = inicializar_estado();
    *etemp = *e;
    LISTA sl = criar_lista();
    *sl = *l;

    if (ver_jogada(sl, etemp, e, h1, h2, h3, h4) == 1) return 0;
    else {
        srand(time(NULL));
        int tamanho = tamanho_lista(l)-1;
        int result = (rand() % tamanho);
        for (i = 0; i < result; i++, l = proximo(l));
        coord = (COORDENADA *) devolve_cabeca(l);
        jogar(e, *coord);
        return 0;
    }
}