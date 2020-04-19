/**
\brief Estruturas de Comandos
*/
#ifndef PROJETOLI2_LISTAS_H
#define PROJETOLI2_LISTAS_H

typedef struct nodo {
    void *valor;
    struct nodo *proximo;
} NODO, *LISTA;


// Cria uma lista vazia
LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);
// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);
// Devolve a cauda da lista
LISTA proximo(LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);
int tamanho_lista(LISTA L);

#endif //PROJETOLI2_LISTAS_H