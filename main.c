#include <stdio.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

/**
@file main.c
Função principal do projeto.
*/

int main()
{
    ESTADO *e;
    e = inicializar_estado();
    while(interpretador(e)==1);


}