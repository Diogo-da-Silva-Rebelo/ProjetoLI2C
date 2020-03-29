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
    FILE *ficheiro;
    ficheiro = fopen("ficheiro.txt","w+");

    while(interpretador(e,ficheiro)==1);


}