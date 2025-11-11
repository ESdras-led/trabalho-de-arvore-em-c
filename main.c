// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"
#include "arvore.h"

#define N 20
#define MAXVAL 500

// Alunos (usar exatamente os nomes e matrículas fornecidos)
const char *nomes[] = {
    "Vinicius Do Nascimento Gomes",
    "Debora Phetra de Melo Bezerra",
    "Laura Felix de Castro Silva",
    "Esdras Khalled De Sena Santos"
};
const char *matriculas[] = {
    "202404095983",
    "202402415701",
    "202402411594",
    "202403322625"
};

void gerar_vetor_unicos(int v[], int n) {
    int cnt = 0;
    while (cnt < n) {
        int r = rand() % MAXVAL + 1; // 1..MAXVAL
        int ok = 1;
        for (int i = 0; i < cnt; ++i)
            if (v[i] == r) {
                ok = 0;
                break;
            }
        if (ok)
            v[cnt++] = r;
    }
}

void imprime_vetor(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%d", v[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    srand((unsigned)time(NULL));

    // 1) Cabeçalho com nomes e matrículas
    printf("Integrantes:\n");
    for (int i = 0; i < 4; ++i) {
        printf(" - %s - %s\n", nomes[i], matriculas[i]);
    }
    printf("\n");

    // 2) Geração do vetor original (20 inteiros únicos 1..500)
    int vetor[N];
    gerar_vetor_unicos(vetor, N);
    printf("Vetor original:\n");
    imprime_vetor(vetor, N);

    // Mantemos cópia original para construir a árvore depois
    int original[N];
    for (int i = 0; i < N; ++i)
        original[i] = vetor[i];

    // 3) Ordenação usando Selection Sort
    long comparacoes = 0;
    selection_sort(vetor, N, &comparacoes);

    printf("\nAlgoritmo utilizado: Selection Sort\n");
    printf("Vetor ordenado:\n");
    imprime_vetor(vetor, N);
    printf("Total de comparacões no algoritmo: %ld\n", comparacoes);

    // 4) Construção da árvore binária com os valores originais
    No *raiz = NULL;
    for (int i = 0; i < N; ++i) {
        raiz = inserir(raiz, original[i]);
    }

    // 5) Percurso em ordem
    printf("\nPercurso da árvore (Em-Ordem):\n");
    percurso_in(raiz);
    printf("\n");

    // 6) Altura da árvore
    int h = altura(raiz);
    printf("\nAltura da árvore (nós): %d\n", h);

    libera(raiz);
    return 0;
}
