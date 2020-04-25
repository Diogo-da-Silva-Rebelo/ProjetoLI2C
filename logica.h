#include "listas.h"
/**
\brief Estrutura Lógica
*/
#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H


void jogar(ESTADO *e, COORDENADA c);
int verifica_jogada (ESTADO *e, COORDENADA c);
int verifica_fim_jog(ESTADO *etemp, COORDENADA c);
int fim_jogo(ESTADO *e);
int compara_coord(COORDENADA c, ESTADO *etemp);
int coordenada_valida(COORDENADA d);
int ver_jogada(LISTA sl,ESTADO *etemp, ESTADO *e);
LISTA l_coord_adj (COORDENADA c,int jogador);
LISTA area_par_possivel (LISTA l, ESTADO *etemp, ESTADO *e);
int area_par(ESTADO *etemp, COORDENADA c);


#endif //PROJETOLI2_LOGICA_H