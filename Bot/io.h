#ifndef BOT_IO_H
#define BOT_IO_H

#include "dados.h"
#include "listas.h"

/**
\brief Estruturas de Comandos
*/
void grava(FILE *ficheiro, ESTADO *e);
void le(FILE *ficheiro,ESTADO *e);
void movs(ESTADO *e,FILE *stdout,int output);

#endif //BOT_IO_H
