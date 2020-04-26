#include "bot.h"
#include "dados.h"
#include <stdio.h>
#include "io.h"


int main(FILE *ficheiro1, FILE *ficheiro2){
    ESTADO *e;
    e = inicializar_estado();
    le(ficheiro1, e);
    grava(ficheiro2, e);
}