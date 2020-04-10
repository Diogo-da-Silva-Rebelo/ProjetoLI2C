#include <stdio.h>
/**
\brief Estrutura de Interface
*/
#ifndef PROJETOLI2_INTERFACE_H
#define PROJETOLI2_INTERFACE_H

void mostrar_tabuleiro(ESTADO *e,FILE *stdout,int cmd);
int interpretador(ESTADO *ae,ESTADO *e, FILE *ficheiro);
void vencedor(int i);
void refresh_board (ESTADO *e, COORDENADA c);
void prompt(ESTADO *e);

#endif //PROJETOLI2_INTERFACE_H
