#include <stdlib.h>
#include "dados.h"

//Função que inicia o estado com o tabuleiro vazio
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
// Falta a resto da inicialização.
    return e;
}

//Função que obtem o número do jogador atual
int obter_jogador_atual(ESTADO *estado) {
    
    return estado->jogador_atual;
}

//Função que obtem o estado atual da casa
int obter_numero_de_jogadas(ESTADO *estado) {

}

//Função que obtem o número de jogadas efetuadas
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {

}