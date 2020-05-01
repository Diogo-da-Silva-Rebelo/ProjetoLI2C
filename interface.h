#include <stdio.h>

/**
\brief Estrutura de Interface
*/
#ifndef PROJETOLI2_INTERFACE_H
#define PROJETOLI2_INTERFACE_H

int interpretador(ESTADO *ae,ESTADO *e, FILE *ficheiro);
void mostrar_tabuleiro(ESTADO *e,FILE *stdout,int cmd);
void prompt(ESTADO *e);
void vencedor(int i);

#endif //PROJETOLI2_INTERFACE_H