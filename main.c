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
    FILE *ficheiro,*ficheiroaux;
    ficheiro = fopen("ficheiro.txt","w+");
    ficheiroaux = fopen("ficheiroaux.txt","w+");
    while(interpretador(e,ficheiro,ficheiroaux)==1);


}