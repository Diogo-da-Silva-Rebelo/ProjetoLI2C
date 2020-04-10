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
void mostrar_tabuleiro(ESTADO *e,FILE *stdout,int cmd) {
    COORDENADA c;
    for (int i = 8; i > 0; i--) {
        if (cmd == 2) fprintf(stdout, "%d ", i);
        for (int j = 0; j <= 7; j++) {
            c.linha = 8 - i;
            c.coluna = j;
            if (cmd == 1) fprintf(stdout, "%c", obter_estado_casa(e, c));
            else fprintf(stdout, "%c ", obter_estado_casa(e, c));
        }
        fprintf(stdout, "\n");
    }
    if (cmd == 2) fprintf(stdout, "  a b c d e f g h \n");
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
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.linha = c.linha;
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.coluna = c.coluna;
        e->jogador_atual = 1;
        e->num_jogadas++;

    }
    else {e->jogador_atual = 2;
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
    mostrar_tabuleiro(e,stdout,2);

    printf("\n");

    printf ("Próximo jogador: %d\n",obter_jogador_atual(e));

    printf ("Última jogada: %c%d\n",obter_ultima_jogada(e).coluna+97,obter_ultima_jogada(e).linha+1);

    printf("Número de jogadas feitas: %d\n",obter_numero_de_jogadas(e));

    printf("Último comando: %d\n",obter_comando(e));

    printf("------------------------------------------------------#------------------------------------------------------\n");
}

/**
\brief Função que interpreta o comando dado pelo utilizador. Primeiro verifica se o jogador já não tem mais hipóteses de jogada.
 \param e Estado recebido.
 \returns Verdadeiro ou falso (1 ou 0) se o comando dado é valido.
*/
int interpretador(ESTADO *e, FILE *ficheiro,FILE *ficheiroaux) {


    char linha[BUF_SIZE];
    char col[2], lin[2];
    prompt(e);
    printf("Jogador %d, introduza uma jogada: ", obter_jogador_atual(e));

    if (fgets(linha, BUF_SIZE, stdin) == NULL) {
        return 0;
    }

    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};

        jogar(e, coord);

        e->num_comando = 1;

        int r = fim_jogo(e);
        if (r == 1 || r == 2) {
            printf("\n                                                           Parabéns ao Jogador %d!", r);
            return 0;
        }

        return 1;
    }

    if (strcmp(linha, "gr\n")==0) {
        e->num_comando = 2;

        grava(ficheiro, e);

        return 1;
    }

    if (strcmp(linha, "ler\n")==0) {
        e->num_comando = 3;

        le(ficheiro,e);

        return 1;
    }

    if (strcmp(linha, "movs\n")==0) {
        e->num_comando = 5;

        movs(e, stdout, 2);

        return 1;
    }

    if (linha[0] == 'p' && linha[1] == 'o' && linha[2] == 's' && linha[3] == ' ' &&
        ((strlen(linha) == 6 && linha[4] >= 48 && linha[4] <= 57) ||
         (strlen(linha) == 7 && linha[4] > 48 && linha[4] <= 57 && linha[5] >= 48 && linha[5] <= 57))) {

        *(linha + 4) -= 47;
        *(linha + 5) -= 47;




        return 1;
    }

    if (strcmp(linha, "Q\n") == 0) {

        printf("Prazer!");
        
        return 0;
    }
}