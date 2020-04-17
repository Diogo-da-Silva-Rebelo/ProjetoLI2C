#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/**
@file listas.c
Funções que respondem a determinados comandos.
*/

LISTA criar_lista(){
    LISTA l;
    l = malloc(sizeof(LISTA));
    return l;
}


LISTA insere_cabeca(LISTA L, void *valor){
    (L->valor)=valor;
    return L;
}


void *devolve_cabeca(LISTA L){
    return L->valor;
}


LISTA proximo(LISTA L){
    return L->proximo;
}


LISTA remove_cabeca(LISTA L){
    LISTA l = criar_lista();
    l=L->valor;
    free(L);
    return l;
}

int lista_esta_vazia(LISTA L){
    return L==NULL ? 0:1;
}