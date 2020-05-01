#ifndef RASTROSLI2_LISTAS_H
#define RASTROSLI2_LISTAS_H

/**
\brief Estruturas de Comandos
*/
typedef struct nodo {
    void *valor;
    struct nodo *proximo;
} NODO, *LISTA;


LISTA criar_lista();
void *devolve_cabeca(LISTA L);
LISTA insere_cabeca(LISTA L, void *valor);
int lista_esta_vazia(LISTA L);
LISTA proximo(LISTA L);
LISTA remove_cabeca(LISTA L);
int tamanho_lista(LISTA L);

#endif //RASTROSLI2_LISTAS_H
