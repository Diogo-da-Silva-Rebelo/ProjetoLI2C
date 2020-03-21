#include <stdlib.h>
#include "dados.h"

/**
@file dados.c
Funções que alteram o estado
*/

/**
\brief Função que inicia o estado com o tabuleiro vazio
*/
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->ultima_jogada.coluna= 4;
    e->ultima_jogada.linha= 4;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 4 && j == 4) e->tab[i][j] == BRANCA;
            else e->tab[i][j] == VAZIO;
        }
    }
    return e;
}


/**
\brief Função que obtem o número do jogador atual
*/
int obter_jogador_atual(ESTADO *estado) {
    return estado->jogador_atual;
}


/**
\brief Função que obtém a última jogada
*/
COORDENADA obter_ultima_jogada(ESTADO *estado){
    return estado->ultima_jogada;
}


/**
\brief Função que obtem o número de jogadas efetuadas
*/
int obter_numero_de_jogadas(ESTADO *estado) {
    return (estado->num_jogadas)/2;
}


/**
\brief Função que obtem o estado atual da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    return e->tab[c.coluna][c.linha];
}

/**
\brief Função que obtem o estado da próxima casa
*/
CASA obter_estado_proxima(ESTADO *e,COORDENADA c){
    return tab[c.linha][c.coluna];
}