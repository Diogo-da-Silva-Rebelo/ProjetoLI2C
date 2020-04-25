#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "logica.h"
#include "interface.h"
#include "io.h"

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
    if (!verifica_jogada(e, c)) printf("Jogada impossível, tente novamente.\n");
    else refresh_board(e, c);
}


/**
\brief Função que verifica se a jogada é válida. Para ser válido, a coordenada precisa de
 ser adjacente à última jogada e o seu estado precisa de ser VAZIO.
 \param e Estado recebido;
 \param c Última coordenada recebida pelo jogador.
 \returns Verdadeiro ou falso (1 ou 0, respetivamente) quando à possibilidade da jogada.
 */
int verifica_jogada (ESTADO *e, COORDENADA c) {
    int reslinha = c.linha - obter_ultima_jogada(e).linha;
    int rescoluna = c.coluna - obter_ultima_jogada(e).coluna;
    CASA casa = obter_estado_casa(e, c);

    return (reslinha >= (-1) && reslinha <= 1 && rescoluna >= (-1) && rescoluna <= 1 &&
        (casa == VAZIO || casa == UM || casa == DOIS)) ? 1:0;
}


/**
\brief Função que verifica se, com a jogada feita, o jogo acaba.
 \param etemp Estado temporário que serve para testes;
 \param c Coordenada que é jogada.
*/
int verifica_fim_jog(ESTADO *etemp, COORDENADA c) {
    jogar(etemp, c);
    return (fim_jogo(etemp) != 3) ? 1:0;
}


/**
\brief Função que verifica se o jogo acabou. Testa todas as possibilidades de jogada.
 \param e Estado.
 \returns o número do jogador vencedor (1 ou 2),
  um número que mostra que ainda há hipoteses de jogar (3),
  ou outro número que mostra que o jogo já acabou mas não há vencedores (0).
*/
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
            if (coordenada_valida(c) && verifica_jogada(e,c))
                result++;
        }

    if (result == 0)
        return (obter_jogador_atual(e) == 1) ? 2 : 1;
    return 3;
}


/**
\brief Função que compara duas coordenadas.
 \param c Coordenada da lista;
 \param d Coordenada mais vantajosa ao jogador.
 \param e Estado do jogo.
*/
int compara_coord(COORDENADA c,ESTADO *e) {
    int resultadoc = c.coluna - obter_ultima_jogada(e).coluna;
    int resultadol = c.linha - obter_ultima_jogada(e).linha;
    resultadol = (obter_jogador_atual(e)==2)? (-1*resultadol):(resultadol);
    return (verifica_jogada(e, c)) &&
           ((resultadol == 0 && resultadoc == -1) || (resultadol == -1 && resultadoc >= -1 && resultadoc <= 1)) ? 1 : 0;
}


/**
\brief Função que verifica se a coordenada é válida
 \param c Coordenada.
 \returns Verdadeiro ou falso.
*/
int coordenada_valida(COORDENADA c) {
    return (c.linha >= 0 && c.linha <= 7 && c.coluna >= 0 && c.coluna <= 8) ? 1:0;
}


/**
\brief Função que verifica se a coordenada é jogável
 \param sl Lista das jogadas possíveis;
 \param etemp Estado temporário;
 \param e Estado do jogo.
 \returns Verdadeiro ou falso.
*/
int ver_jogada(LISTA l,ESTADO *etemp, ESTADO *e) {
    while (!lista_esta_vazia(l)) {
        COORDENADA *coord;
        coord = (COORDENADA *) devolve_cabeca(l);
        *etemp = *e;

        if (compara_coord(*coord, e) || (verifica_fim_jog(etemp, *coord))) {
            jogar(e, *coord);
            return 1;
        }
        l=proximo(l);
        *etemp = *e;
    }
    return 0;
}


/**
\brief Função que cria uma lista com todas as coordenadas adjacentes.
 \param ultcrd Última coordenada do jogador
 \param jogador Número do jogador
 \returns Lista.
*/
LISTA l_coord_adj (COORDENADA ultcrd,int jogador) {
    LISTA l = criar_lista();
    int num1 = (jogador == 1) ? 1 : -1;
    int num2 = (jogador == 1) ? 1 : -1;

    for (int z = 1; z >= -1; z--) {
        for (int i = 1; i >= -1; i--) {
            COORDENADA *coord;
            coord = malloc(sizeof(COORDENADA));
            (*coord).linha = ultcrd.linha + num2;
            (*coord).coluna = ultcrd.coluna + num1;
            l = insere_cabeca(l, coord);
            num1 = (jogador == 1) ? num1 - 1 : num1 + 1;
        }
        (jogador == 1) ? num2-- : num2++;
        num1 = (jogador == 1) ? 1 : -1;
    }
    return l;
}