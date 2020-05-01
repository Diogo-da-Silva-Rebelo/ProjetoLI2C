#include "bot.h"
#include "dados.h"
#include <stdio.h>
#include "io.h"


int main(int argc, char **argv){
    ESTADO *e;
    e = inicializar_estado();
    le(ficheiro1, e);
    grava(ficheiro2, e);
}