#include "dados.h"
#include <stdio.h>
#include "logica.h"
#include "interface.h"

/**
@file logica.c
Funções que verificam as jogadas
*/

/**
\brief Função que inicia o jogo
*/
int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
   if (verifica_jogada(e,c)==0) {
       printf("Erro! Introduza uma jogada válida.");
       scanf("%d", &c.linha);
       scanf("%d", &c.coluna);
       jogar(e, c);}
   else {refresh_board(e,c);
         prompt(e);}
   return 1;
}

/**
\brief Função que verifica se a jogada é válida
*/
int verifica_jogada (ESTADO *e, COORDENADA c) {

    int plinha = c.linha;
    int pcoluna = c.coluna;
    int alinha = e->ultima_jogada.linha;
    int acoluna = e->ultima_jogada.coluna;
    int rlinha = plinha-alinha;
    int rcoluna = pcoluna-acoluna;

    if (pcoluna>8 || pcoluna<1 || plinha>8 || pcoluna<1)
        return 0;
    else {
        if (obter_estado_casa(e,c) == VAZIO) {
            if (rlinha >= (-1) && rlinha <= 1 && rcoluna >= (-1) && rcoluna <= 1)
                return 1;
            else return 0;}
        else return 0;}
}


/**
\brief Função que verifica se o jogo acabou
*/
int fim_jogo(ESTADO *e){

    COORDENADA c = e->ultima_jogada;
    COORDENADA c1,c2,c3,c4,c5,c6;
    c1.linha=c.linha+1;
    c1.coluna=c.coluna;

    c2.linha=c.linha-1;
    c2.coluna=c.coluna;

    c3.linha=c.linha;
    c3.coluna=c.coluna+1;

    c4.linha=c.linha;
    c4.coluna=c.coluna-1;

    c5.linha=c.linha+1;
    c5.coluna=c.coluna+1;

    c6.linha=c.linha;
    c6.coluna=c.coluna-1;

    int p1 = verifica_jogada(e,c1);
    int p2 = verifica_jogada(e,c2);
    int p3 = verifica_jogada(e,c3);
    int p4 = verifica_jogada(e,c4);
    int p5 = verifica_jogada(e,c5);
    int p6 = verifica_jogada(e,c6);

    if (c.linha==1 && c.coluna==1){
        return 1;}
    else {if (c.linha == 8 && c.coluna == 8) {
              return 1;}
          else {if (p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0 || p5 == 0 || p6 == 0) {
                    return 1;}
                else return 0;
               }
         }
}