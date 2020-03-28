#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "interface.h"
#include "dados.h"


/**
@file io.c
Funções que respondem a determinados comandos.
*/

void grava(FILE *ficheiro,ESTADO *e){
    FILE *fp;
    fp = fopen(ficheiro,"w+");
    mostrar_tabuleiro(e,fp);
    fclose(fp);
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
void movs(ESTADO *e) {
    int j = obter_numero_de_jogadas(e);
    printf("__| Jogador 1 | Jogador 2\n");

    for (int i = 1; i < j; i++) {
        int ljum = e->jogadas[i].jogador1.linha + 1;
        char cjum = e->jogadas[i].jogador1.coluna + 97;
        int ljdois = e->jogadas[i].jogador2.linha + 1;
        char cjdois = e->jogadas[i].jogador2.coluna + 97;

        printf("%d |    %c%d     |    %c%d\n", i, cjum, ljum, cjdois, ljdois);
    }

/**
\brief Assim significa que o último jogador que jogou foi o jogador 1.
\brief Imprime a última jogada.
*/
    if (obter_numero_de_jogadas(e) > 0) {
        if (obter_jogador_atual(e) == 2) {
            int ljum = e->jogadas[j].jogador1.linha + 1;
            char cjum = e->jogadas[j].jogador1.coluna + 97;

            printf("%d |    %c%d\n", j, cjum, ljum);
        } else {
            int ljum = e->jogadas[j].jogador1.linha + 1;
            char cjum = e->jogadas[j].jogador1.coluna + 97;
            int ljdois = e->jogadas[j].jogador2.linha + 1;
            char cjdois = e->jogadas[j].jogador2.coluna + 97;

            printf("%d |    %c%d     |    %c%d\n", j, cjum, ljum, cjdois, ljdois);
        }
    }
    printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
}

