#define BUF_SIZE 1024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dados.h"
#include "logica.h"
#include "io.h"

/**
@file interface.c
Funções que alteram o tabuleiro.
*/

/**
\brief Função que mostra o tabuleiro ao receber um estado
\brief i é linha; j é coluna;
 \param e Estado recebido.
*/
void mostrar_tabuleiro(ESTADO *e,FILE *stdout) {
    COORDENADA c;

    for (int i = 7; i>=0; i--) {
        fprintf(stdout,"%d ",i+1);
        for (int j = 0; j <= 7; j++) {
            c.linha = 7 - i;
            c.coluna = j;
            if (obter_estado_casa(e, c) == BRANCA) fprintf(stdout,"*");
            else {
                if (obter_estado_casa(e, c) == PRETA) fprintf(stdout,"#");
                else {if (c.linha == 7 && c.coluna == 0) fprintf (stdout,"1");
                      else {if (c.linha == 0 && c.coluna == 7) fprintf (stdout,"2");
                            else fprintf(stdout,".");}}
            }
        }
        fprintf(stdout,"\n");
    }
    fprintf (stdout,"  abcdefgh \n");
}

/**
\brief Função que atualiza o tabuleiro com a nova jogada
 \param e Estado recebido.
 \param c Última coordenada dada pelo jogador.
*/
void refresh_board (ESTADO *e, COORDENADA c) {
/**
\brief Nesta parte, atualiza-se o número de jogadas, o jogador atual e o array de jogadas
*/
    if (e->jogador_atual==2) {
        e->jogador_atual = 1;
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.linha = c.linha;
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.coluna = c.coluna;

    }
    else {e->jogador_atual = 2;
          e->num_jogadas = e->num_jogadas+1;
          e->jogadas[obter_numero_de_jogadas(e)].jogador1.linha = c.linha;
          e->jogadas[obter_numero_de_jogadas(e)].jogador1.coluna = c.coluna;
    }

/**
\brief Nesta parte, atualiza-se o número de jogadas, o jogador atual e/ou o array de jogadas
*/
    int ult_lin = 7-(e->ultima_jogada.linha);
    e->tab[ult_lin][e->ultima_jogada.coluna]=PRETA;
    int lin = 7-c.linha;
    e->tab[lin][c.coluna]=BRANCA;

    e->ultima_jogada.linha=(c.linha);
    e->ultima_jogada.coluna=(c.coluna);
}


/**
\brief Função que mostra o tabuleiro, o número de jogadas, o próximo jogador e a última jogada.
 \param e Estado recebido.
 */
void prompt(ESTADO *e){
    mostrar_tabuleiro(e,stdout);

    printf("\n");

    printf ("Próximo jogador: %d\n",obter_jogador_atual(e));

    int linha = e->ultima_jogada.linha;
    linha = linha+1;

    int coluna = e->ultima_jogada.coluna;
    coluna = coluna+97;

    printf ("Última jogada: %c%d\n",coluna,linha);

    int njogadas = e->num_jogadas;
    printf("Número de jogadas feitas: %d\n",njogadas);

    printf("------------------------------------------------------#------------------------------------------------------\n");
}

/**
\brief Função que interpreta o comando dado pelo utilizador. Primeiro verifica se o jogador já não tem mais hipóteses de jogada.
 \param e Estado recebido.
 \returns Verdadeiro ou falso (1 ou 0) se o comando dado é valido.
*/
int interpretador(ESTADO *e,FILE *ficheiro) {
    int r = fim_jogo(e);
    if (r == 1 || r == 2) {
        printf("\n                                                           Parabéns ao Jogador %d!", r);
        return 0;
    } else {

        char linha[BUF_SIZE];
        char col[2], lin[2];
        prompt(e);
        printf("Jogador %d, introduza uma jogada: ",obter_jogador_atual(e));
        if (fgets(linha, BUF_SIZE, stdin) == NULL) {
            return 0;
        }

        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};

            jogar(e, coord,ficheiro);
            return 1;
        }

        if (strlen (linha) == 3 && linha[0]=='g' && linha[1]=='r'){
            grava(ficheiro,e);
            return 1;
        }

        if (strlen(linha)==4 && linha[0]=='l' && linha[1]=='e' && linha[2]=='r'){
            return 1;
        }

        if (strlen(linha)==5 && linha[0]=='m' && linha[1]=='o' && linha[2]=='v' && linha[3]=='s'){
            movs(e,stdout);
            return 1;
        }

        if (strlen(linha)==2 && linha[0]=='Q') {
            printf("Prazer!");
            return 0;
        }
    }
}