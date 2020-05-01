#ifndef RASTROSLI2_INTERFACE_H
#define RASTROSLI2_INTERFACE_H

#include <stdio.h>

/**
\brief Estrutura de Interface
*/
int interpretador(ESTADO *antigoe, ESTADO *e, FILE *ficheiro);
void mostrar_tabuleiro(ESTADO *e,FILE *stdout,int cmd);
void prompt(ESTADO *e);
void vencedor(int jogador);

#endif //RASTROSLI2_INTERFACE_H