#include <stdio.h>
#include "dados.h"
#include "logica.h"
#include "io_aux.h"

/**
@file logica.c
Funções que verificam as jogadas e se o jogo acabou.
*/

/**
\brief Função que inicia o jogo.
 \param e Estado recebido.
 \param c Última coordenada recebida pelo jogador.
*/
void jogar(ESTADO *e, COORDENADA c) {
    if (!verifica_coord(e, c)) printf("Jogada impossível, tente novamente.\n");
    else refresh_board(e, c);
}


/**
\brief Função que verifica se a coordenada é válida. Para ser válido, ela precisa de
 ser adjacente à última coordenada e o estado da sua casa precisa de ser VAZIO, UM ou DOIS.
 \param e Estado recebido;
 \param c Última coordenada recebida pelo jogador.
 \returns Verdadeiro ou falso (1 ou 0, respetivamente) quanto à possibilidade da coordenada.
 */
int verifica_coord(ESTADO *e, COORDENADA c) {
    int reslinha = c.linha - obter_ultima_jogada(e).linha;
    int rescoluna = c.coluna - obter_ultima_jogada(e).coluna;
    CASA casa = obter_estado_casa(e, c);

    return (reslinha >= (-1) && reslinha <= 1 && rescoluna >= (-1) && rescoluna <= 1 &&
            (casa == VAZIO || casa == UM || casa == DOIS)) ? 1:0;
}


/**
\brief Função que verifica se o jogo acabou. Testa todas as possibilidades de jogada.
 \param e Estado.
 \returns o número do jogador vencedor (1 ou 2) ou
  um número que mostra que ainda há hipoteses de jogar (3 ou mais).*/
int fim_jogo(ESTADO *e) {
    COORDENADA ultcrd = obter_ultima_jogada(e);
    COORDENADA c;

    if (ultcrd.linha == 0 && ultcrd.coluna == 0) {
        return 1;
    } else if (ultcrd.linha == 7 && ultcrd.coluna == 7)
        return 2;

    int result = 0;

    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++){
            c.linha=ultcrd.linha+i;
            c.coluna=ultcrd.coluna+j;
            if (coordenada_valida(c) && verifica_coord(e,c))
                result++;
        }

    if (result == 0)
        return (obter_jogador_atual(e) == 1) ? 2 : 1;
    return 2 + result;
}


