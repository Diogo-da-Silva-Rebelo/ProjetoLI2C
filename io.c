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
    ficheiro = fopen("ficheiro.txt","w");
    mostrar_tabuleiro(e,ficheiro);
    movs(e,ficheiro);
    fclose(ficheiro);
}

void set_casa(ESTADO *e, COORDENADA c, char buffer){
    if (buffer=='#') e->tab[c.linha][c.coluna]=PRETA;
    else if (buffer=='*') e->tab[c.linha][c.coluna-2]=BRANCA;
         else e->tab[c.linha][c.coluna-2]=VAZIO;
}

COORDENADA string_to_coordenada(char c, char l){

    COORDENADA coord;
    return coord;
}

void le(FILE *ficheiro,ESTADO *estado){
    ficheiro = fopen("ficheiro.txt","r");
    char linha[11];
    ESTADO *e;
    e = malloc(sizeof(ESTADO));
    e = inicializar_estado();

    char buffer[11];
    int l = 0;
    while(l<8) {
        fgets(buffer,10,ficheiro);
        for(int c = 2; c < 10; c++) set_casa(e, (COORDENADA) {l,c-2}, buffer[c]);

        l++;
        }
    mostrar_tabuleiro(e,stdout);

    fgets(buffer,10,ficheiro);
    fgets(buffer,10,ficheiro);
    fgets(buffer,21,ficheiro);

    int nj = obter_numero_de_jogadas(estado);
    int i = 7, j = 0, k = 19;
    while (nj>0){
      e->jogadas[j].jogador1 = string_to_coordenada(buffer[i],buffer[i+1]);
      e->jogadas[j].jogador2 = string_to_coordenada(buffer[k],buffer[k+1]);
      nj--;
    }

    movs(e,stdout);
    fclose(ficheiro);
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

