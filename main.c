#include <stdio.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

/**
@file main.c
Função principal do projeto
*/

int main()
{
    FILE *fp;
    fp = fopen("dados.txt","w+");
    fclose (fp);

    ESTADO *e = inicializar_estado();
    while (fim_jogo(e)!=1 && interpretador(e,fp));

}