#include <stdlib.h>
#include <stdio.h>
#include "dados.h"
#include "interface.h"

/**
@file dados.c
Funções que alteram o estado.
*/

/**
\brief Função que inicia o estado com o tabuleiro vazio.
  \returns O estado inicializado, com a primeira jogada ser e4.
*/
ESTADO *inicializar_estado() {
    ESTADO *e;
    e = malloc(sizeof(ESTADO));
    e->jogador_atual = 2;
    e->num_jogadas = -1;
    e->ultima_jogada.coluna = 4;
    e->ultima_jogada.linha = 4;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            e->tab[i][j] = VAZIO;
        }
    }
    e->tab[3][4] = BRANCA;
    refresh_board(e,e->ultima_jogada);
    return e;
}


/**
\brief Função que obtém o número do jogador atual.
 \param e Estado recebido.
 \returns O jogador que jogará a seguir.
*/
int obter_jogador_atual(ESTADO *e) {
    return e->jogador_atual;
}


/**
\brief Função que obtém a última jogada.
 \param e Estado recebido.
 \returns A última jogada.
*/
COORDENADA obter_ultima_jogada(ESTADO *e){
    return e->ultima_jogada;
}


/**
\brief Função que obtem o número de jogadas efetuadas
 \param e Estado recebido.
 \returns O número de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *e) {
    return e->num_jogadas;
}


/**
\brief Função que obtem o estado atual da casa.
 \param e Estado recebido.
 \returns Estado da coordenada.
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    return e->tab[c.linha][c.coluna];
}
