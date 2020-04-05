#include "dados.h"
#include <stdio.h>
#include "logica.h"
#include "interface.h"

/**
@file logica.c
Funções que verificam as jogadas.
*/

/**
\brief Função que inicia o jogo.
 \param e Estado recebido.
 \param c Última coordenada recebida pelo jogador.
*/
int jogar(ESTADO *ae,ESTADO *e, COORDENADA c, FILE *ficheiro){
    if (verifica_jogada(e,c)==0) {
        printf ("Jogada impossível, tente novamente.\n");
        interpretador(ae,e,ficheiro);}
    else{
    refresh_board(e,c);
    }

    return 1;
}

/**
\brief Função que verifica se a jogada é válida.
 \param e Estado recebido.
 \param c Última coordenada recebida pelo jogador.
 \returns Verdadeiro ou falso (1 ou 0, respetivamente) quando à possibilidade da jogada.
 */
int verifica_jogada (ESTADO *e, COORDENADA c) {

    c.linha = 7-c.linha;
    int pcoluna = c.coluna;
    int alinha = 7-e->ultima_jogada.linha;
    int acoluna = e->ultima_jogada.coluna;
    int rlinha = c.linha-alinha;
    int rcoluna = pcoluna-acoluna;

    if (rlinha >= (-1) && rlinha <= 1 && rcoluna >= (-1) && rcoluna <= 1){
        if (obter_estado_casa(e,c) == VAZIO) return 1;
        else return 0;}
    else return 0;
}



/**
\brief Função que verifica se o jogo acabou.
 \param e Estado recebido.
 \returns o número do jogador vencedor (1 ou 2),
  um número que mostra que ainda há hipoteses de jogar (3),
  ou outro número que mostra que o jogo já acabou mas não há vencedores (0).
*/
int fim_jogo(ESTADO *e){

    COORDENADA c = e->ultima_jogada;
    COORDENADA c1,c2,c3,c4,c5,c6,c7,c8;
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

    c6.linha=c.linha-1;
    c6.coluna=c.coluna-1;

    c7.linha=c.linha+1;
    c7.coluna=c.coluna-1;

    c8.linha=c.linha-1;
    c8.coluna=c.coluna+1;

    int p1 = verifica_jogada(e,c1);
    int p2 = verifica_jogada(e,c2);
    int p3 = verifica_jogada(e,c3);
    int p4 = verifica_jogada(e,c4);
    int p5 = verifica_jogada(e,c5);
    int p6 = verifica_jogada(e,c6);
    int p7 = verifica_jogada(e,c7);
    int p8 = verifica_jogada(e,c8);

    if (c.linha==0 && c.coluna==0){
        return 1;}
    else {if (c.linha == 7 && c.coluna == 7) {
              return 2;}
          else {if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0 && p7 == 0 && p8 == 0) {
                    return (e->jogador_atual == 1)? 1:2;}
                else {if (p1 == 1 || p2 == 1 || p3 == 1 || p4 == 1 || p5 == 1 || p6 == 1 || p7 == 1 || p8 == 1)
                      return 3;
                      else return 0;};
               }
         }
}