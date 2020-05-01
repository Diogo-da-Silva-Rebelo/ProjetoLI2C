#include "dados.h"
#include "listas.h"

/**
\brief Estruturas de Comandos
*/
#ifndef PROJETOLI2_IO_H
#define PROJETOLI2_IO_H

void grava(FILE *ficheiro, ESTADO *e);
void jog(ESTADO *e);
void jog2 (ESTADO *e);
void le(FILE *ficheiro,ESTADO *e);
void movs(ESTADO *e,FILE *stdout,int l);
void pos(ESTADO *e,int i);

#endif //PROJETOLI2_IO_H