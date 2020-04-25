#define BUF_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "logica.h"
#include "io.h"

/**
@file interface.c
Funções que modificam a interface do jogo.
*/

/**
\brief Função que mostra o vencedor do jogo.
 \param i Jogador do vencedor.
*/
void vencedor(int i) {
    printf("  ______________________________________________________________________________________________________\n");
    printf("||‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾||\n");
    printf("||    ______       ||       ______     ||       ______     _______              ________     _   _   _  ||\n");
    printf("||  ||‾‾‾‾‾‾||    ||||    ||‾‾‾‾‾‾||  ||||    ||‾‾‾‾‾‾|| ||_______| \\\\      || | _______|   | | | | | | ||\n");
    printf("||  ||______||   ||  ||   ||______|| ||  ||   ||______|| ||_____    ||\\\\    || | |______    | | | | | | ||\n");
    printf("||  ||‾‾‾‾‾‾     ||__||   ||\\\\‾‾‾    ||__||   ||\\\\‾‾‾‾   ||_____|   ||  \\\\  || |_______ |   |_| |_| |_| ||\n");
    printf("||  ||          ||____||  ||  \\\\    ||____||  ||  ‾‾‾‾|| ||_______  ||    \\\\||  ______| |    _   _   _  ||\n");
    printf("||  ||         ||      || ||    \\\\ ||      || ||______|| ||_______| ||      \\\\ |________|   |_| |_| |_| ||\n");
    printf("||______________________________________________________________________________________________________||\n");
    printf("||‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾||\n");

    if (i == 1) {
        printf("||                                          ‾‾‾‾‾‾|                                                     ||\n");
        printf("||                                          ‾‾‾‾| |                                                     ||\n");
        printf("||                                              | |                                                     ||\n");
        printf("||                                              | |                                                     ||\n");
        printf("||                                              | |                                                     ||\n");
        printf("||                                              | |                                                     ||\n");

    } else {
        printf("||                                           |‾‾‾‾‾‾‾‾‾‾|                                               ||\n");
        printf("||                                            ‾‾‾‾‾‾‾ | |                                               ||\n");
        printf("||                                                    | |                                               ||\n");
        printf("||                                            ________| |                                               ||\n");
        printf("||                                            ||‾‾‾‾‾‾| |______                                         ||\n");
        printf("||                                            ||______|_|_____/                                         ||\n");
    }
}


/**
\brief Função que mostra o tabuleiro ao receber um estado
\brief i é linha; j é coluna;
 \param e Estado;
 \param stdout Apontador do ficheiro para onde vai imprimir o tabuleiro;
 \param cmd Número do comando.
*/
void mostrar_tabuleiro(ESTADO *e,FILE *stdout,int cmd) {
    COORDENADA c;
    for (int i = 8; i > 0; i--) {
        if (cmd == 2) fprintf(stdout, "%d ", i);
        for (int j = 0; j <= 7; j++) {
            c.linha = i - 1;
            c.coluna = j;
            if (cmd == 1) fprintf(stdout, "%c", obter_estado_casa(e, c));
            else fprintf(stdout, "%c ", obter_estado_casa(e, c));
        }
        fprintf(stdout, "\n");
    }
    if (cmd == 2) fprintf(stdout, "  a b c d e f g h \n");
}

/**
\brief Função que atualiza o tabuleiro com a nova jogada.
 \param e Estado;
 \param c Última coordenada dada pelo jogador.
*/
void refresh_board (ESTADO *e, COORDENADA c) {
/**
\brief Nesta parte, atualiza-se o número de jogadas, o jogador atual e o array de jogadas.
*/
    if (e->jogador_atual == 2) {
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.linha = c.linha;
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.coluna = c.coluna;
        e->jogador_atual = 1;
        e->num_jogadas++;

    } else {
        e->jogador_atual = 2;
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.linha = c.linha;
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.coluna = c.coluna;
    }
/**
\brief Nesta parte, atualiza-se o número de jogadas, o jogador atual e/ou o array de jogadas.
*/
    int ult_lin = 7 - (e->ultima_jogada.linha);
    e->tab[ult_lin][e->ultima_jogada.coluna] = PRETA;
    int lin = 7 - c.linha;
    e->tab[lin][c.coluna] = BRANCA;

    e->ultima_jogada.linha = (c.linha);
    e->ultima_jogada.coluna = (c.coluna);
}


/**
\brief Função que mostra o tabuleiro, o número de jogadas, o próximo jogador, a última jogada e o último comando usado.
 \param e Estado recebido.
 */
void prompt(ESTADO *e) {
    printf("\n");

    printf(" _____________________________________________________________________________________________________\n");
    printf("|    Próximo jogador    |    Última jogada    |    Número de jogadas feitas    |    Último comando    |\n");
    printf("|           %d           |         %c%d          |               %02d               |          %d           |\n",
           obter_jogador_atual(e),
           obter_ultima_jogada(e).coluna + 97, obter_ultima_jogada(e).linha + 1, obter_numero_de_jogadas(e),
           obter_comando(e));
    printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}


/**
\brief Função que interpreta o comando dado pelo utilizador.
 \param ae Estado antigo, usado para o comando pos;
 \param e Estado recebido;
 \param ficheiro Apontador para o ficheiro, usado para os comandos ler e gr.
 \returns Verdadeiro ou falso (1 ou 0) se o comando dado é valido.
*/
int interpretador(ESTADO *ae,ESTADO *e, FILE *ficheiro) {
    char linha[BUF_SIZE];
    mostrar_tabuleiro(e, stdout, 2);

    int r = fim_jogo(e);
    if (r == 1 || r == 2) {
        vencedor(r);
        return 0;
    }

    prompt(e);
    printf("Jogador %d, introduza uma jogada: ", obter_jogador_atual(e));

    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    char col[2], lin[2];
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        e->num_comando = 1;
        return 1;
    }

    if (strcmp(linha, "gr\n") == 0) {
        e->num_comando = 2;
        grava(ficheiro, e);
        return 1;
    }

    if (strcmp(linha, "ler\n") == 0) {
        e->num_comando = 3;
        le(ficheiro, e);
        return 1;
    }

    if (linha[0] == 'p' && linha[1] == 'o' && linha[2] == 's' && linha[3] == ' ' &&
        ((strlen(linha) == 6 && linha[4] >= 48 && linha[4] <= 57) ||
         (strlen(linha) == 7 && linha[4] > 48 && linha[4] <= 57 && linha[5] >= 48 && linha[5] <= 57))) {

        *(linha + 4) -= 48;
        int numero = *(linha + 4);
        if (strlen(linha) == 7) {
            *(linha + 5) -= 48;
            numero = (*(linha + 4)) * 10 + (*(linha + 5));
        }

        if (obter_comando(e) != 4) *ae = *e;

        if (numero > obter_numero_de_jogadas(ae)) {
            printf("Impossível, coloque um número inferior ao número de jogadas\n");
            return 1;
        } else if (numero > obter_numero_de_jogadas(e)) *e = *ae;

        if (numero == 0) {
            free(e);
            e = inicializar_estado();
        } else pos(e, numero);

        e->num_comando = 4;
        return 1;
    }

    if (strcmp(linha, "movs\n") == 0) {
        e->num_comando = 5;
        movs(e, stdout, 2);
        return 1;
    }

    if (strcmp(linha, "jog\n") == 0) {
        jog(e);
        e->num_comando = 6;
        return 1;
    }

    if (strcmp(linha, "Q\n") == 0) {
        printf("Prazer!");
        return 0;
    }
    return 0;
}