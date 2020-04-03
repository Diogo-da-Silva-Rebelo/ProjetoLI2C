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
\brief Função que imprimir as jogadas anteriores.
*/
void movs(ESTADO *e,FILE *stdout) {
    int j = obter_numero_de_jogadas(e);
    fprintf(stdout,"__| Jogador 1 | Jogador 2\n");
    int i = 0;
    int ljum,cjum,ljdois,cjdois;

    for (i; i < j; i++) {
        ljum = e->jogadas[i].jogador1.linha + 1;
        cjum = e->jogadas[i].jogador1.coluna + 97;
        ljdois = e->jogadas[i].jogador2.linha + 1;
        cjdois = e->jogadas[i].jogador2.coluna + 97;

        fprintf(stdout,"%02d|    %c%d     |    %c%d\n", i+1, cjum, ljum, cjdois, ljdois);
    }

/**
\brief Imprime a última jogada no caso do jogador 2.
\brief Caso contrário, a última linha já foi imprimida.
*/
    if (obter_jogador_atual(e) == 2) {
       ljum = e->jogadas[j].jogador1.linha + 1;
       cjum = e->jogadas[j].jogador1.coluna + 97;
       fprintf(stdout,"%02d|    %c%d\n", j+1, cjum, ljum);
       }
    fprintf(stdout,"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
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