#include "listas.h"

/**
\brief Estrutura Lógica
*/
#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H

int area_par(ESTADO *etemp, COORDENADA c);
LISTA area_par_possivel (LISTA l, ESTADO *e);
int compara_coord(COORDENADA c, ESTADO *etemp);
int coordenada_valida(COORDENADA d);
int fim_jogo(ESTADO *e);
LISTA hipord(LISTA l,ESTADO *e);
int jogada_favoravel(LISTA sl, ESTADO *e);
void jogar(ESTADO *e, COORDENADA c);
LISTA l_coord_adj (COORDENADA c,int jogador);
COORDENADA str_to_coord (char *coordenada);
int verifica_coord (ESTADO *e, COORDENADA c);
int verifica_fim_jogo(ESTADO *etemp, COORDENADA c);

#endif //PROJETOLI2_LOGICA_H