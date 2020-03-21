#include "dados.h"
#include "interface.h"

/**
@file main.c
Função principal do projeto
*/

int main()
{
    ESTADO *e = inicializar_estado();
    if (fim_jogo(e)==1){
        return 0;}
    else {
        interpretador(e);
    }
}