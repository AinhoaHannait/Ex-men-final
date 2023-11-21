#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j,k;

void llenarMatriz(int matriz[30][30]) {
    for (i = 0; i < 30; ++i) {
        for (j = 0; j < 30; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int matriz[30][30]) {
    for (i = 0; i < 30; ++i) {
        for (j = 0; j < 30; ++j) {

            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int matrizA[30][30], int matrizB[30][30], int matrizC[30][30]) {
    for (i = 0; i < 30; ++i) {
        for (j = 0; j < 30; ++j) {
            matrizC[i][j] = 0;
            for (k = 0; k < 30; ++k) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main() {
clock_t inicio = clock();
    srand(time(NULL));
    int matrizA[30][30];
    int matrizB[30][30];
    int matrizC[30][30];

    llenarMatriz(matrizA);
    llenarMatriz(matrizB);


    printf("Matriz 1:\n");
    imprimirMatriz(matrizA);

    printf("\nMatriz 2:\n");
    imprimirMatriz(matrizB);


    multiplicarMatrices(matrizA, matrizB, matrizC);

    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC * 1000.0;
    printf("\nTiempo de ejecución: %.2f milisegundos\n", tiempo);

    printf("\nMatriz de resultado:\n");
    imprimirMatriz(matrizC);
    
    printf("Espero haber sido de ayuda:)");

    return 0;
}
