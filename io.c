#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "interface.h"
#include "dados.h"


/**
@file io.c
Funções que respondem a determinados comandos.
*/

/**
\brief Função que grava o estado atual do jogo num ficheiro que se chama "Ficheiro.txt"
*/
void grava(FILE *ficheiro,ESTADO *e){
    fopen(ficheiro,"w+");
    mostrar_tabuleiro(e,ficheiro);
    movs(e,ficheiro);
    fclose(ficheiro);
}

void le(FILE *ficheiro,ESTADO *e){
    FILE *fp;
    fp = fopen(ficheiro,"r+");
    mostrar_tabuleiro(e,fp);
    fclose(fp);
}

/**
\brief Função que dá as jogadas anteriores.
*/
void movs(ESTADO *e,FILE *stdout) {
    int j = obter_numero_de_jogadas(e);
    fprintf(stdout,"__| Jogador 1 | Jogador 2\n");

    for (int i = 1; i < j; i++) {
        int ljum = e->jogadas[i].jogador1.linha + 1;
        char cjum = e->jogadas[i].jogador1.coluna + 97;
        int ljdois = e->jogadas[i].jogador2.linha + 1;
        char cjdois = e->jogadas[i].jogador2.coluna + 97;

        fprintf(stdout,"%02d|    %c%d     |    %c%d\n", i, cjum, ljum, cjdois, ljdois);
    }

/**
\brief Assim significa que o último jogador que jogou foi o jogador 1.
\brief Imprime a última jogada.
*/
    if (obter_numero_de_jogadas(e) > 0) {
        if (obter_jogador_atual(e) == 2) {
            int ljum = e->jogadas[j].jogador1.linha + 1;
            char cjum = e->jogadas[j].jogador1.coluna + 97;

            fprintf(stdout,"%02d|    %c%d\n", j, cjum, ljum);
        } else {
            int ljum = e->jogadas[j].jogador1.linha + 1;
            char cjum = e->jogadas[j].jogador1.coluna + 97;
            int ljdois = e->jogadas[j].jogador2.linha + 1;
            char cjdois = e->jogadas[j].jogador2.coluna + 97;

            fprintf(stdout,"%02d|    %c%d     |    %c%d\n", j, cjum, ljum, cjdois, ljdois);
        }
    }
    fprintf(stdout,"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
}

