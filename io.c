#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "interface.h"
#include "dados.h"
#include "logica.h"


/**
@file io.c
Funções que respondem a determinados comandos.
*/

/**
\brief Função que grava o estado atual do jogo num ficheiro que se chama "Ficheiro.txt"
*/
void grava(FILE *ficheiro,ESTADO *e) {
    ficheiro = fopen("ficheiro.txt", "w");
    mostrar_tabuleiro(e, ficheiro, 1);
    movs(e, ficheiro, 1);
    fclose(ficheiro);
}

COORDENADA str_to_coord (char *coordenada) {
    COORDENADA coord = {*coordenada - 'a', *(coordenada + 1) - '1'};
    return coord;
}

void str_to_casa (char *linha, ESTADO *estado, int l) {
    int i = 0;
    while (i < 8) {
        if (linha[i] == '*') {
            estado->tab[l][i] = BRANCA;
            i++;
        } else if (linha[i] == '#') {
            estado->tab[l][i] = PRETA;
            i++;
        } else if (linha[i] == '1') {
            estado->tab[l][i] = UM;
            i++;
        } else if (linha[i] == '2') {
            estado->tab[l][i] = DOIS;
            i++;
        } else {
            estado->tab[l][i] = VAZIO;
            i++;
        }
    }
}

void armazena_jogada(COORDENADA c1, COORDENADA c2, int i, ESTADO *estado){
    estado->jogadas[i].jogador1 = c1;
    estado->jogadas[i].jogador2 = c2;
}

void le(FILE *ficheiro,ESTADO *estado) {
    ficheiro = fopen("ficheiro.txt", "r");

    free(estado);
    estado = inicializar_estado();

    int num_jog;
    int i = 0;
    char jog1[BUF_SIZE];
    char jog2[BUF_SIZE];
    char linha[BUF_SIZE];

    while ((fgets(linha, BUF_SIZE, ficheiro) != NULL) && (i < 8)) {
        str_to_casa(linha, estado, i);
        i++;
    }

    i = 0;

    while (fgets(linha, BUF_SIZE, ficheiro) != NULL) {
        int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
        if (num_tokens == 3) {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = str_to_coord(jog2);
            armazena_jogada(c1, c2, i, estado);

            estado->num_jogadas++;
            estado->jogador_atual = 1;
            estado->ultima_jogada = c2;

            i++;

        } else {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = {-1, -1};
            armazena_jogada(c1, c2, i, estado);

            estado->jogador_atual = 2;
            estado->ultima_jogada = c1;
        }
    }
    fclose(ficheiro);
}


/**
\brief Função que imprime todas as jogadas anteriores.
*/
void movs(ESTADO *e,FILE *stdout,int l) {
    int j = obter_numero_de_jogadas(e);
    int i = 0;
    int ljum, cjum, ljdois, cjdois;

    if (l == 2) fprintf(stdout, "__| Jogador 1 | Jogador 2\n");


    for (i; i < j; i++) {
        ljum = e->jogadas[i].jogador1.linha + 1;
        cjum = e->jogadas[i].jogador1.coluna + 97;
        ljdois = e->jogadas[i].jogador2.linha + 1;
        cjdois = e->jogadas[i].jogador2.coluna + 97;

        if (l == 1) fprintf(stdout, "%02d: %c%d %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
        else fprintf(stdout, "%02d|    %c%d     |    %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
    }

    if (obter_jogador_atual(e) == 2) {
        ljum = e->jogadas[j].jogador1.linha + 1;
        cjum = e->jogadas[j].jogador1.coluna + 97;
    }

    if (l == 1) fprintf(stdout, "%02d: %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
    else {
        fprintf(stdout, "%02d|    %c%d\n", i + 1, cjum, ljum, cjdois, ljdois);
        fprintf(stdout, "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    }
}


void pos(ESTADO *e,int i,FILE *ficheiroaux) {
    if (i < obter_numero_de_jogadas(e)) {
        e->jogador_atual = 1;
        e->ultima_jogada = e->jogadas[i].jogador2;
        e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = BRANCA;

        int itemp = i + 1;

        while (itemp <= obter_numero_de_jogadas(e)) {
            int linha1 = e->jogadas[itemp].jogador1.linha;
            int coluna1 = e->jogadas[itemp].jogador1.coluna;
            int linha2 = e->jogadas[itemp].jogador2.linha;
            int coluna2 = e->jogadas[itemp].jogador2.coluna;

            e->tab[7 - linha1][coluna1] = VAZIO;
            e->tab[7 - linha2][coluna2] = VAZIO;
            itemp++;
        }
        e->num_jogadas = i;

    }
}