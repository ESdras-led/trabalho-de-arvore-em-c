// arvore.h
#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* cria_no(int valor);
No* inserir(No* raiz, int valor);
void percurso_pre(No* raiz);
void percurso_in(No* raiz);
void percurso_pos(No* raiz);
int altura(No* raiz);
void libera(No* raiz);

#endif // ARVORE_H
