#include "listas.h"
/**
\brief Estrutura Lógica
*/
#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H


void jogar(ESTADO *e, COORDENADA c);
int verifica_coord (ESTADO *e, COORDENADA c);
int verifica_fim_jogo(ESTADO *etemp, COORDENADA c);
int fim_jogo(ESTADO *e);
int compara_coord(COORDENADA c, ESTADO *etemp);
int coordenada_valida(COORDENADA d);
int jogada_favoravel(LISTA sl, ESTADO *e);
LISTA l_coord_adj (COORDENADA c,int jogador);
LISTA area_par_possivel (LISTA l, ESTADO *e);
int area_par(ESTADO *etemp, COORDENADA c);
LISTA hipord(LISTA l,ESTADO *e);


#endif //PROJETOLI2_LOGICA_H