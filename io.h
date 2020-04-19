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
void armazena_jogada(COORDENADA c1, COORDENADA c2, int i, ESTADO *estado);
void le(FILE *ficheiro,ESTADO *e);
void movs(ESTADO *e,FILE *stdout,int l);
void pos(ESTADO *e,int i);
int verifica_fim_jog(ESTADO *etemp, ESTADO *e, COORDENADA c);
int compara_coord(COORDENADA c,COORDENADA d);
int ver_jogada(LISTA sl,ESTADO *etemp, ESTADO *e,COORDENADA h1,COORDENADA h2,COORDENADA h3,COORDENADA h4);
int jog(ESTADO *e);

#endif //PROJETOLI2_IO_H