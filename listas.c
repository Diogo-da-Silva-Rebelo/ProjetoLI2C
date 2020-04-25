/**
\brief Estruturas de Comandos
*/
#ifndef PROJETOLI2_LISTAS_H
#define PROJETOLI2_LISTAS_H


/**
\brief Tipo de dados para as listas.
*/
typedef struct nodo {
    void *valor;
    struct nodo *proximo;
} NODO, *LISTA;


LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
void *devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);
LISTA remove_cabeca(LISTA L);
int lista_esta_vazia(LISTA L);
int tamanho_lista(LISTA L);

#endif //PROJETOLI2_LISTAS_H