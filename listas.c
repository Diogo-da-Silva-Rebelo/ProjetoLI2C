#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/**
@file listas.c
Funções que respondem a determinados comandos.
*/

LISTA criar_lista(){
    LISTA l = malloc(sizeof(NODO));
    return l;
}


LISTA insere_cabeca(LISTA L, void *val) {
    LISTA s =  malloc(sizeof(NODO));
    s->valor = val;
    s->proximo = L;
    return s;
}


void * devolve_cabeca(LISTA L){
    return L->valor;
}


LISTA proximo(LISTA L){
    return L->proximo;
}


LISTA remove_cabeca(LISTA L){
    LISTA l = criar_lista();
    *l=*L->proximo;
    free(L);
    return l;
}

int lista_esta_vazia(LISTA L){
    return L==NULL ? 1:0;
}

int tamanho_lista(LISTA L){
    int i;
    for(i = 0;!lista_esta_vazia(L);i++){
        L=proximo(L);
    }
    return i;
}