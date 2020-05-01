#ifndef RASTROSLI2_IO_H
#define RASTROSLI2_IO_H

#include "dados.h"
#include "listas.h"

/**
\brief Estruturas de Comandos
*/
void grava(FILE *ficheiro, ESTADO *e);
void jog(ESTADO *e);
void jog2 (ESTADO *e);
void le(FILE *ficheiro,ESTADO *e);
void movs(ESTADO *e,FILE *stdout,int output);
void pos(ESTADO *e,int jogada);

#endif //RASTROSLI2_IO_H
