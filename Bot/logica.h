#ifndef RASTROSLI2_LOGICA_H
#define RASTROSLI2_LOGICA_H

#include "listas.h"

/**
\brief Estrutura Lógica
*/
void jogar(ESTADO *e, COORDENADA c);
int verifica_fim_jogo(ESTADO *etemp, COORDENADA c);
int fim_jogo(ESTADO *e);

#endif //RASTROSLI2_LOGICA_H