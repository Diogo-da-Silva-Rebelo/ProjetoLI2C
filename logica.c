#include <stdio.h>
#include "dados.h"
#include "logica.h"
#include "interface.h"

/**
@file logica.c
Funções que verificam as jogadas e se o jogo acabou.
*/

/**
\brief Função que inicia o jogo.
 \param e Estado recebido.
 \param c Última coordenada recebida pelo jogador.
*/
void jogar(ESTADO *e, COORDENADA c){
    if (verifica_jogada(e,c)==0) printf ("Jogada impossível, tente novamente.\n");
    else refresh_board(e,c);
}

/**
\brief Função que verifica se a jogada é válida. Para ser válido, a coordenada precisa de
 ser adjacente à última jogada e o seu estado precisa de ser VAZIO.
 \param e Estado recebido;
 \param c Última coordenada recebida pelo jogador.
 \returns Verdadeiro ou falso (1 ou 0, respetivamente) quando à possibilidade da jogada.
 */
int verifica_jogada (ESTADO *e, COORDENADA c) {

    int reslinha = c.linha - obter_ultima_jogada(e).linha;
    int rescoluna = c.coluna - obter_ultima_jogada(e).coluna;

    if (reslinha >= (-1) && reslinha <= 1 && rescoluna >= (-1) && rescoluna <= 1 && obter_estado_casa(e,c)!=BRANCA) return 1;
    else return 0;
}



/**
\brief Função que verifica se o jogo acabou. Testa todas as possibilidades de jogada.
 \param e Estado.
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

    int p1 = verifica_jogada(e, c1);
    int p2 = verifica_jogada(e, c2);
    int p3 = verifica_jogada(e, c3);
    int p4 = verifica_jogada(e, c4);
    int p5 = verifica_jogada(e, c5);
    int p6 = verifica_jogada(e, c6);
    int p7 = verifica_jogada(e, c7);
    int p8 = verifica_jogada(e, c8);

    if (c.linha == 0 && c.coluna == 0) {
        return 1;
    } else {
        if (c.linha == 7 && c.coluna == 7) {
            return 2;
        } else {
            if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0 && p7 == 0 && p8 == 0) {
                return (e->jogador_atual == 1) ? 2 : 1;
            } else {
                if (p1 == 1 || p2 == 1 || p3 == 1 || p4 == 1 || p5 == 1 || p6 == 1 || p7 == 1 || p8 == 1)
                    return 3;
                else return 0;
            };
        }
    }
}