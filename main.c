#include "dados.h"
#include "interface.h"

/**
@file main.c
Função principal do projeto
*/

int main()
{
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}