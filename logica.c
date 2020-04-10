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
void jogar(ESTADO *e, COORDENADA c){
    if (verifica_jogada(e,c)==COORDENADA_INVALIDA) printf ("Jogada impossível, tente novamente.\n");
    else refresh_board(e,c);
}

/**
\brief Função que verifica se a jogada é válida.
 \param e Estado recebido.
 \param c Última coordenada recebida pelo jogador.
 \returns Verdadeiro ou falso (1 ou 0, respetivamente) quando à possibilidade da jogada.
 */
ERROS verifica_jogada (ESTADO *e, COORDENADA c) {

    c.linha = 7 - c.linha;
    int pcoluna = c.coluna;
    int alinha = 7 - e->ultima_jogada.linha;
    int acoluna = e->ultima_jogada.coluna;
    int rlinha = c.linha - alinha;
    int rcoluna = pcoluna - acoluna;

    if (rlinha >= (-1) && rlinha <= 1 && rcoluna >= (-1) && rcoluna <= 1 && obter_estado_casa(e, c) == VAZIO)
        return OK;
    return COORDENADA_INVALIDA;
}



/**
\brief Função que verifica se o jogo acabou.
 \param e Estado recebido.
 \returns o número do jogador vencedor (1 ou 2),
  um número que mostra que ainda há hipoteses de jogar (3),
  ou outro número que mostra que o jogo já acabou mas não há vencedores (0).
*/
int fim_jogo(ESTADO *e) {

    COORDENADA c = e->ultima_jogada;
    COORDENADA c1, c2, c3, c4, c5, c6, c7, c8;
    c1.linha = c.linha + 1;
    c1.coluna = c.coluna;

    c2.linha = c.linha - 1;
    c2.coluna = c.coluna;

    c3.linha = c.linha;
    c3.coluna = c.coluna + 1;

    c4.linha = c.linha;
    c4.coluna = c.coluna - 1;

    c5.linha = c.linha + 1;
    c5.coluna = c.coluna + 1;

    c6.linha = c.linha - 1;
    c6.coluna = c.coluna - 1;

    c7.linha = c.linha + 1;
    c7.coluna = c.coluna - 1;

    c8.linha = c.linha - 1;
    c8.coluna = c.coluna + 1;

    ERROS p1 = verifica_jogada(e, c1);
    ERROS p2 = verifica_jogada(e, c2);
    ERROS p3 = verifica_jogada(e, c3);
    ERROS p4 = verifica_jogada(e, c4);
    ERROS p5 = verifica_jogada(e, c5);
    ERROS p6 = verifica_jogada(e, c6);
    ERROS p7 = verifica_jogada(e, c7);
    ERROS p8 = verifica_jogada(e, c8);

    if (c.linha == 0 && c.coluna == 0) {
        return 1;
    } else {
        if (c.linha == 7 && c.coluna == 7) {
            return 2;
        } else {
            if (p1 == COORDENADA_INVALIDA && p2 == COORDENADA_INVALIDA && p3 == COORDENADA_INVALIDA &&
                p4 == COORDENADA_INVALIDA
                && p5 == COORDENADA_INVALIDA && p6 == COORDENADA_INVALIDA && p7 == COORDENADA_INVALIDA &&
                p8 == COORDENADA_INVALIDA) {
                return (e->jogador_atual == 1) ? 1 : 2;
            } else {
                if (p1 == OK || p2 == OK || p3 == OK || p4 == OK || p5 == OK || p6 == OK || p7 == OK || p8 == OK)
                    return 3;
                else return 0;
            };
        }
    }
}