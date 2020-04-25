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
\brief Função que armazena as duas coordenadas no array das jogadas no estado
 \param c1 Coordenada do jogador 1;
 \param c2 Coordenada do jogador 2;
 \param i Número da jogada;
 \param estado Estado.
*/
void armazena_jogada(COORDENADA c1, COORDENADA c2, int i, ESTADO *estado) {
    estado->jogadas[i].jogador1 = c1;
    estado->jogadas[i].jogador2 = c2;
}


/**
\brief Função que coloca altera o estado de cada casa de acordo com a char string recebida.
 \param linha Apontador para a string que é uma linha do tabuleiro;
 \param estado Estado;
 \param l Número da linha.
*/
void str_to_casa (char *linha, ESTADO *estado, int l) {
    for (int i = 0; i < 8; i++) {
        if (linha[i] == '*')
            estado->tab[l][i] = BRANCA;
        else if (linha[i] == '#')
            estado->tab[l][i] = PRETA;
        else if (linha[i] == '1')
            estado->tab[l][i] = UM;
        else if (linha[i] == '2')
            estado->tab[l][i] = DOIS;
        else
            estado->tab[l][i] = VAZIO;
    }
}


COORDENADA obter_x_jogada(ESTADO *e,int i,int jogador){
    return jogador==1 ? e->jogadas[i].jogador1:e->jogadas[i].jogador2;
}