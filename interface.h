#ifndef PROJETOLI2_INTERFACE_H
#define PROJETOLI2_INTERFACE_H

void mostrar_tabuleiro(ESTADO *e,FILE *stdout,int i);
int interpretador(ESTADO *ae,ESTADO *e, FILE *ficheiro);
void refresh_board (ESTADO *e, COORDENADA c);
void prompt(ESTADO *e);

#endif //PROJETOLI2_INTERFACE_H
