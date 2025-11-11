// arvore.c
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No* cria_no(int valor) {
    No* n = (No*) malloc(sizeof(No));
    if (!n) return NULL;
    n->valor = valor;
    n->esq = n->dir = NULL;
    return n;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return cria_no(valor);
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void percurso_in(No* raiz) {
    if (!raiz) return;
    percurso_in(raiz->esq);
    printf("%d ", raiz->valor);
    percurso_in(raiz->dir);
}

int altura(No* raiz) {
    if (!raiz) return 0;
    int he = altura(raiz->esq);
    int hd = altura(raiz->dir);
    return 1 + (he > hd ? he : hd);
}

void libera(No* raiz) {
    if (!raiz) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}
