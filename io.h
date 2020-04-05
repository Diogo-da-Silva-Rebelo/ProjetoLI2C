/**
\brief Estruturas de Comandos
*/
#ifndef PROJETOLI2_IO_H
#define PROJETOLI2_IO_H

#include "dados.h"

void grava(FILE *ficheiro, ESTADO *e);
void armazenar_jogada(ESTADO *e,JOGADA j,int l);
COORDENADA str_to_coord (char *jogada);
void str_to_casa (char *linha, ESTADO *estado, int l);
void le(FILE *ficheiro, ESTADO *e);
void movs(ESTADO *e,FILE *stdout,int l);
void pos(ESTADO *ae,ESTADO *e,int i);

#endif //PROJETOLI2_IO_H