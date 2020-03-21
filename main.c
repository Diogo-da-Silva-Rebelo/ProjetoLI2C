#include "dados.h"
#include "interface.h"

/**
Função principal
 */
int main()
{
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}