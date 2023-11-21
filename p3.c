#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaSecuencial(int arr[], int elemento, int num) {
  int i;
  for (i = 0; i < num; i++) {
    if (arr[i] == elemento) {
      return (i + 1);
    }
  }
  return -1;
}

int busquedaBinaria(int arr[], int elemento, int primero, int ultimo) {
  if (primero <= ultimo) {
    int mitad = (primero + ultimo) / 2;

    if (elemento == arr[mitad]) {
      return (mitad + 1);
    } else if (elemento < arr[mitad]) {
      return busquedaBinaria(arr, elemento, primero, mitad - 1);
    } else {
      return busquedaBinaria(arr, elemento, mitad + 1, ultimo);
    }
  }
  return -1;
}

float calcularPromedio(float tiempos[], int n) {
  float suma = 0;
  int i;
  for (i = 0; i < n; i++) {
    suma += tiempos[i];
  }
  return suma / n;
}

int indiceMaximo(float tiempos[], int n) {
  int i, indice = 0;
  float maximo = -10000;
  for (i = 0; i < n; i++) {
    if (tiempos[i] > maximo) {
      indice = i;
      maximo = tiempos[i];
    }
  }
  return indice;
}

int indiceMinimo(float tiempos[], int n) {
  int i, indice = 0;
  float minimo = 10000;
  for (i = 0; i < n; i++) {
    if (tiempos[i] < minimo) {
      indice = i;
      minimo = tiempos[i];
    }
  }
  return indice;
}

int main() {
  int arreglo[500000];
  float tiemposBinaria[100], tiemposSecuencial[100], acumuladoBinaria = 0, acumuladoSecuencial = 0;
  int i, elemento;

  for (i = 0; i < 500000; i++) {
    arreglo[i] = i;
  }

  for (i = 0; i < 100; i++) {
    elemento = rand() % 500000;

    
    clock_t inicioSecuencial = clock();
    busquedaSecuencial(arreglo, elemento, 500000);
    clock_t finSecuencial = clock();
    tiemposSecuencial[i] = ((double)(finSecuencial - inicioSecuencial) / CLOCKS_PER_SEC);
    acumuladoSecuencial += tiemposSecuencial[i];

   
    clock_t inicioBinaria = clock();
    busquedaBinaria(arreglo, elemento, 0, 500000);
    clock_t finBinaria = clock();
    tiemposBinaria[i] = ((double)(finBinaria - inicioBinaria) / CLOCKS_PER_SEC);
    acumuladoBinaria += tiemposBinaria[i];
  }
  printf("\nBusqueda secuencial\n");
  printf("Promedio del tiempo: %f\n", calcularPromedio(tiemposSecuencial, 100));
  printf("Tiempo Max de busquedaSecuencial: %f\n", tiemposSecuencial[indiceMaximo(tiemposSecuencial, 100)]);
  printf("Tiempo min de busquedaSecuencial: %f\n", tiemposSecuencial[indiceMinimo(tiemposSecuencial, 100)]);
  
  printf("\nBusqueda binaria");
  printf("\nPromedio del tiempo: %f\n", calcularPromedio(tiemposBinaria, 100));
  printf("Tiempo Max de busquedaBinaria: %f\n", tiemposBinaria[indiceMaximo(tiemposBinaria, 100)]);
  printf("Tiempo min de busquedaBinaria: %f\n", tiemposBinaria[indiceMinimo(tiemposBinaria, 100)]);

  return 0;
}

