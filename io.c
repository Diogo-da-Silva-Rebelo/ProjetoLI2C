#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "interface.h"
#include "dados.h"
#include "logica.h"


/**
@file io.c
Funções que respondem a determinados comandos.
*/

/**
\brief Função que grava o estado atual do jogo num ficheiro que se chama "Ficheiro.txt"
*/
void grava(FILE *ficheiro,ESTADO *e){
    ficheiro = fopen("ficheiro.txt","w");
    mostrar_tabuleiro(e,ficheiro,1);
    fprintf(ficheiro,"\n");
    movs(e,ficheiro,1);
    fclose(ficheiro);
}

COORDENADA str_to_coord (char *jogada){
    COORDENADA coord = {*jogada - 'a', *(jogada+1) - '1'};
    return coord;
}

void str_to_casa (char *linha, ESTADO *estado, int l) {
    int i = 0;
    while (i < 8) {
        if (linha[i] == "*") {
            estado->tab[l][i] = BRANCA;
            i++;
        } else if (linha[i] == "#") {
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

void armazenar_jogada(ESTADO *e,JOGADA j,int l){
    e->jogadas[l].jogador1=j.jogador1;
    e->jogadas[l].jogador2=j.jogador2;
}

void le(FILE *ficheiro,ESTADO *e) {

    ficheiro = fopen("ficheiro.txt", "w+");
    char linha[BUF_SIZE];
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, ficheiro) != NULL) {
        int num_jog;
        char jog1[BUF_SIZE];
        char jog2[BUF_SIZE];
        int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
        if (num_tokens == 3) {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = str_to_coord(jog2);
            armazenar_jogada(e, (JOGADA) {c1, c2}, num_jog);
        } else {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = {-1, -1};
            armazenar_jogada(e, (JOGADA) {c1, c2}, num_jog);
        }
        fclose(ficheiro);


    }
}


/**
\brief Função que imprimir as jogadas anteriores.
*/
void movs(ESTADO *e,FILE *stdout,int l) {
    int j = obter_numero_de_jogadas(e);
    int i = 0;
    int ljum, cjum, ljdois, cjdois;

    if (l == 1) {
        for (i; i < j; i++) {
            ljum = e->jogadas[i].jogador1.linha + 1;
            cjum = e->jogadas[i].jogador1.coluna + 97;
            ljdois = e->jogadas[i].jogador2.linha + 1;
            cjdois = e->jogadas[i].jogador2.coluna + 97;
            fprintf(stdout, "%02d: %c%d %c%d\n", i+1, cjum, ljum, cjdois, ljdois);
        }

        if (obter_jogador_atual(e) == 2) {
            ljum = e->jogadas[j].jogador1.linha + 1;
            cjum = e->jogadas[j].jogador1.coluna + 97;
            fprintf(stdout, "%02d: %c%d\n", i+1, cjum, ljum);

        }
    } else {
        fprintf(stdout, "__| Jogador 1 | Jogador 2\n");
        for (i; i < j; i++) {
            ljum = e->jogadas[i].jogador1.linha + 1;
            cjum = e->jogadas[i].jogador1.coluna + 97;
            ljdois = e->jogadas[i].jogador2.linha + 1;
            cjdois = e->jogadas[i].jogador2.coluna + 97;

            fprintf(stdout, "%02d|    %c%d     |    %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
        }
/**
\brief Imprime a última jogada no caso do jogador 2.
\brief Caso contrário, a última linha já foi imprimida.
*/
        if (obter_jogador_atual(e) == 2) {
            ljum = e->jogadas[j].jogador1.linha + 1;
            cjum = e->jogadas[j].jogador1.coluna + 97;
            fprintf(stdout, "%02d|    %c%d\n", j + 1, cjum, ljum);
        }
        fprintf(stdout, "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    }
}


void pos(ESTADO *e,int i) {
    ESTADO *nestado;
    nestado = inicializar_estado();
    int a = i;
    int k = 0;
    if (i < obter_numero_de_jogadas(e)) {
        while (a>1){
            refresh_board(nestado, e->jogadas[k].jogador1);
            refresh_board(nestado, e->jogadas[k].jogador2);
            printf("ahsdhvukjd");
            a--;
            k++;
        }
        printf("ddd");}

    if (obter_jogador_atual(e) == 2) {
        refresh_board(nestado, e->jogadas[i].jogador1);
        *e = *nestado;
    }
}