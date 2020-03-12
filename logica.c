#include "dados.h"
#include <stdio.h>
#include "logica.h"

//Função que inicia o jogo
int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}