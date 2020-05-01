#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/**
@file listas.c
Funções que alteram as listas.
*/

/**
\brief Função que cria uma lista.
 \returns Uma lista.
*/
LISTA criar_lista() {
    LISTA l = malloc(sizeof(NODO));
    l->valor= NULL;
    return l;
}


/**
\brief Função que insere um valor na cabeça da lista.
 \param l Lista;
 \param valor Valor que vai ser colocado na cabeça da lista.
 \returns  Lista alterada.
*/
LISTA insere_cabeca(LISTA L, void *val) {
    LISTA s = malloc(sizeof(NODO));
    s->valor = val;
    s->proximo = L;
    return s;
}


/**
\brief Função que devolve a cabeça da lista.
 \param l Lista.
 \returns  Valor que estava na cabeça.
*/
void * devolve_cabeca(LISTA L) {
    return L->valor;
}


/**
\brief Função que devolve a cauda da lista.
 \param l Lista.
 \returns  A lista inicial mas sem a cabeça.
*/
LISTA proximo(LISTA L) {
    return L->proximo;
}


/**
\brief Função que remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda da lista.
 \param l Lista.
 \returns  A lista inicial mas sem a cabeça.
*/
LISTA remove_cabeca(LISTA L) {
    LISTA l = L->proximo;
    free(L->valor);
    return l;
}


/**
\brief Função que verifica se a lista está vazia.
 \param l Lista.
 \returns  Verdadeiro ou falso.
*/
int lista_esta_vazia(LISTA L) {
    return L->valor == NULL ? 1 : 0;
}


/**
\brief Função que calcula o tamanho da lista.
 \param l Lista.
 \returns  O tamanho.
*/
int tamanho_lista(LISTA L) {
    int i;
    for (i = 0; !lista_esta_vazia(L); i++, L = proximo(L));
    return i;
}