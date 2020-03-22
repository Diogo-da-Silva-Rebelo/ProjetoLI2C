#ifndef PROJETOLI2_INTERFACE_H
#define PROJETOLI2_INTERFACE_H

void mostrar_tabuleiro(ESTADO *e);
void file_m_tab(CASA *tab);
int interpretador(ESTADO *e);
void refresh_board (ESTADO *e, COORDENADA c);
void prompt(ESTADO *e);

#endif //PROJETOLI2_INTERFACE_H
