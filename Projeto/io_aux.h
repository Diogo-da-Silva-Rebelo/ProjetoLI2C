#ifndef RASTROSLI2_IO_AUX_H
#define RASTROSLI2_IO_AUX_H

#include "dados.h"
#include "listas.h"

int area_par(ESTADO *etemp, COORDENADA c);
LISTA area_par_possivel (LISTA l, ESTADO *e);
int compara_coord(COORDENADA c, ESTADO *etemp);
int coordenada_valida(COORDENADA d);
LISTA hipord(LISTA l,ESTADO *e);
int jogada_favoravel(LISTA sl, ESTADO *e);
LISTA l_coord_adj (COORDENADA c,int jogador);
COORDENADA str_to_coord (const char *coordenada);
int verifica_coord (ESTADO *e, COORDENADA c);

#endif //RASTROSLI2_IO_AUX_H