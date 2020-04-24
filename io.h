#include "dados.h"
#include "listas.h"
/**
\brief Estruturas de Comandos
*/
#ifndef PROJETOLI2_IO_H
#define PROJETOLI2_IO_H


void grava(FILE *ficheiro, ESTADO *e);
COORDENADA str_to_coord (char *coordenada);
void str_to_casa (char *linha, ESTADO *estado, int l);
void le(FILE *ficheiro,ESTADO *e);
void movs(ESTADO *e,FILE *stdout,int l);
void pos(ESTADO *e,int i);
LISTA hipord(LISTA l,ESTADO *e);
int jog(ESTADO *e);

#endif //PROJETOLI2_IO_H
