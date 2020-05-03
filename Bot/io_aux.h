#ifndef BOT_IO_AUX_H
#define BOT_IO_AUX_H

#include "dados.h"
#include "listas.h"

/**
@file io_aux.h
Funções auxiliares dos comandos.
*/

/**
\brief Função que compara se uma coordenada é igual a uma coordenada favorável.
 \param c Coordenada da lista;
 \param e Estado do jogo.
 \returns Verdadeiro ou Falso.
*/
int compara_coord(COORDENADA c, ESTADO *etemp);


/**
\brief Função que verifica se a coordenada é válida
 \param c Coordenada.
 \returns Verdadeiro ou falso.
*/
int coordenada_valida(COORDENADA d);


/**
\brief Função que elimina as jogadas não possíveis.
 \param l Lista de todas as jogadas;
 \param e Estado do jogo;
 \returns Uma lista com todas as jogadas possíveis.
*/
LISTA hipord(LISTA l,ESTADO *e);


/**
\brief Função que verifica se a coordenada é jogável para as coordenadas mais favoráveis.
 \param l Lista das jogadas possíveis;
 \param e Estado do jogo.
 \returns Verdadeiro ou falso.
*/
int jogada_favoravel(LISTA sl, ESTADO *e);


/**
\brief Função que cria uma lista com todas as coordenadas adjacentes.
 \param ultcrd Última coordenada do jogador;
 \param jogador Número do jogador.
 \returns Lista.
*/
LISTA l_coord_adj (COORDENADA c,int jogador);


/**
\brief Função que transforma uma string em coordenada.
 \param coordenada String do tipo letra-numero.
 \returns Coordenada.
*/
COORDENADA str_to_coord (const char *coordenada);

/**
\brief Função que verifica se, com a jogada feita, o jogo acaba.
 \param etemp Estado temporário que serve para testes;
 \param c Coordenada que é jogada.
 \returns Verdadeiro ou falso.
*/
int verifica_fim_jogo(ESTADO *etemp, COORDENADA c);

#endif //BOT_IO_AUX_H