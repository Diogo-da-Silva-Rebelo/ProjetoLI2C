#include <stdlib.h>
#include "dados.h"

//Função que inicia o estado com o tabuleiro vazio
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for(int i=0; i<8;i++)
        for(int j=0; j<8; j++) e->tab[i][j]=VAZIO;
    return e;
}

// Função que obtem o número do jogador atual
int obter_jogador_atual(ESTADO *estado) {
    return estado->jogador_atual;
}

//Função que obtem o estado atual da casa
int obter_numero_de_jogadas(ESTADO *estado) {
    return (estado->num_jogadas)/2;
}

//Função que obtem o número de jogadas efetuadas
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    int templinha=e->ultima_jogada.linha;
    int tempcoluna=e->ultima_jogada.coluna;

    int coluna = c.coluna;
    int linha = c.linha;

    CASA res= VAZIO;
    int jog=obter_numero_de_jogadas(e); jog*=2;

    for(int i=0; i<jog; i++) {
        int linha1= e->jogadas[i].jogador1.linha;
        int coluna1= e->jogadas[i].jogador1.coluna;
        int linha2= e->jogadas[i].jogador2.linha;
        int coluna2= e->jogadas[i].jogador2.coluna;

        if((linha1==linha && coluna1==coluna) || (linha2==linha && coluna2==coluna)) {
            res=PRETA;
            i=jog+1;
        }
    }
    if(templinha==linha && tempcoluna==coluna) {
        res=BRANCA;
        return res;
    }
    else return res;
}