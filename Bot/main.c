#include "dados.h"
#include <stdio.h>
#include "io.h"


int main(int argc, char **argv){
    ESTADO *e;
    e = inicializar_estado();
    le(argv[1], e);
    grava(argv[2], e);
}