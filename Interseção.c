#include <stdio.h>

#define TAMANHO_ARRAY 20

int main() {
    int array1[TAMANHO_ARRAY];
    int array2[TAMANHO_ARRAY];
    int interseccao[TAMANHO_ARRAY];
    int tamanho_interseccao = 0;
    int i, j, k;

    // leitura dos arrays
    for (i = 0; i < TAMANHO_ARRAY; i++) {
        scanf("%d", &array1[i]);
    }
    for (i = 0; i < TAMANHO_ARRAY; i++) {
        scanf("%d", &array2[i]);
    }

    // identifica��o da intersec��o
    for (i = 0; i < TAMANHO_ARRAY; i++) {
        for (j = 0; j < TAMANHO_ARRAY; j++) {
            if (array1[i] == array2[j]) {
                // verifica se o n�mero j� foi adicionado � intersec��o
                for (k = 0; k < tamanho_interseccao; k++) {
                    if (array1[i] == interseccao[k]) {
                        break;
                    }
                }
                // se n�o foi adicionado, adiciona e incrementa o tamanho da intersec��o
                if (k == tamanho_interseccao) {
                    interseccao[tamanho_interseccao++] = array1[i];
                }
            }
        }
    }

    // ordena��o da intersec��o
    for (i = 0; i < tamanho_interseccao; i++) {
        for (j = i+1; j < tamanho_interseccao; j++) {
            if (interseccao[i] > interseccao[j]) {
                int temp = interseccao[i];
                interseccao[i] = interseccao[j];
                interseccao[j] = temp;
            }
        }
    }

    // impress�o da intersec��o ou "VAZIO"
    if (tamanho_interseccao == 0) {
        printf("VAZIO\n");
    } else {
        for (i = 0; i < tamanho_interseccao; i++) {
            printf("%d\n", interseccao[i]);
        }
    }

    return 0;
}
