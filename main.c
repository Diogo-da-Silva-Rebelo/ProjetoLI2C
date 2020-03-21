#include "dados.h"
#include "interface.h"
#include "logica.h"

/**
@file main.c
Função principal do projeto
*/

int main()
{
    ESTADO *e = inicializar_estado();
    while (fim_jogo(e)!=1 && interpretador(e));

}