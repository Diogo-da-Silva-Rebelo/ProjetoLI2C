#include <stdlib.h>
#include "dados.h"
#include "interface.h"

/**
@file dados.c
Funções que alteram o estado e que vão buscar dados a ele.
*/

/**
\brief Função que inicia o estado com o tabuleiro vazio.
  \returns O estado inicializado, com a primeira jogada em e4.
*/
ESTADO *inicializar_estado() {
    ESTADO *e;
    e = malloc(sizeof(ESTADO));
    e->jogador_atual = 2;
    e->num_comando = 1;
    e->num_jogadas = -1;
    e->ultima_jogada.coluna = 4;
    e->ultima_jogada.linha = 4;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            e->tab[i][j] = VAZIO;
        }
    }

    e->tab[3][4] = BRANCA;
    e->tab[7][0] = UM;
    e->tab[0][7] = DOIS;

    refresh_board(e, e->ultima_jogada);

    return e;
}


/**
\brief Função que obtém o número do jogador atual.
 \param e Estado.
 \returns O jogador que jogará a seguir.
*/
int obter_jogador_atual(ESTADO *e) {
    return e->jogador_atual;
}


/**
\brief Função que obtém a última jogada.
 \param e Estado.
 \returns A última jogada.
*/
COORDENADA obter_ultima_jogada(ESTADO *e) {
    return e->ultima_jogada;
}


/**
\brief Função que obtem o número de jogadas efetuadas
 \param e Estado.
 \returns O número de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *e) {
    return e->num_jogadas;
}


/**
\brief Função que obtem o estado atual da casa.
 \param e Estado.
 \returns Estado da coordenada.
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    return e->tab[7 - c.linha][c.coluna];
}


/**
\brief Função que obtém o número do comando.
 \param e Estado.
 \returns Número do comando, existem diferentes números consoante o tipo de comando.
*/
int obter_comando(ESTADO *e) {
    return e->num_comando;
}


/**
\brief Função que obtém a coordenada jogada pelo jogador na jogada i.
 \param e Estado;
 \param i Número da jogada;
 \param j Número do jogador.
 \returns Número do comando, existem diferentes números consoante o tipo de comando.
*/
COORDENADA obter_coordenada(ESTADO *e, int i, int j) {
    return (j == 1) ? e->jogadas[i].jogador1 : e->jogadas[i].jogador2;
}