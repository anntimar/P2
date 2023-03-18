#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n� da lista encadeada
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Fun��o para adicionar um novo n� no final da lista
void adicionar_no(No **inicio, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Fun��o para verificar se a lista B � subconjunto da lista A
int eh_subconjunto(No *a, No *b) {
    No *atual_a = a;
    No *atual_b = b;

    while (atual_b != NULL) {
        int encontrado = 0;
        atual_a = a;
        while (atual_a != NULL) {
            if (atual_a->valor == atual_b->valor) {
                encontrado = 1;
                break;
            }
            atual_a = atual_a->prox;
        }
        if (!encontrado) {
            return 0;
        }
        atual_b = atual_b->prox;
    }

    return 1;
}

// Fun��o para imprimir os elementos da lista
void imprimir_lista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    int n, m, valor, i;

    // Lendo a primeira lista
    scanf("%d", &n);
    No *lista_a = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        adicionar_no(&lista_a, valor);
    }

    // Lendo a segunda lista
    scanf("%d", &m);
    No *lista_b = NULL;
    for (i = 0; i < m; i++) {
        scanf("%d", &valor);
        adicionar_no(&lista_b, valor);
    }

    // Verificando se a lista B � subconjunto da lista A
    if (eh_subconjunto(lista_a, lista_b)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    // Liberando a mem�ria alocada para as listas
    No *atual = lista_a;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    atual = lista_b;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    return 0;
}
