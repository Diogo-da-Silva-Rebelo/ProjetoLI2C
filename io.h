#ifndef PROJETOLI2_IO_H
#define PROJETOLI2_IO_H

#include "dados.h"

void grava(FILE *ficheiro, ESTADO *e);
COORDENADA string_to_coordenada(char c, char l);
void set_casa(ESTADO *e, COORDENADA c, char buffer);
void le(FILE *ficheiro, ESTADO *estado);
void movs(ESTADO *e,FILE *stdout);

#endif //PROJETOLI2_IO_H