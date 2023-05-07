#include <stdio.h>
#include <stdlib.h>
// Crear matriz de n vertices m Aristas
int n, m;
// Función para crear matriz de adyacencia
void creaMatriz(int matriz[][n],int arr[][2])
{
    // Inicializar todos los valores de la matriz a 0
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            matriz[i][j] = 0;
        }
    }
    // Recorrer arreglo de aristas
    for (int i = 0; i < m; i++) {
        // Encuentra adyacencia
        int x = arr[i][0];
        int y = arr[i][1];
        // Coloca 1 en cada adyacencia
        matriz[x][y] = 1;
        matriz[y][x] = 1;
    }
}
// Función ´para imprimir la matriz de adyacencia
void imprimeMatriz(int matriz[][n])
{
// Recorrer e imprimir la matriz
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
    // Programa principal
int main()
{
    // Número de vértices
    n = 3;
    // Aristas
    int arr[][2] = { { 0, 1 }, { 0, 2 } };
    // Numero de Aristas
    m = sizeof(arr) / sizeof(arr[0]);
    // Matriz de Adyacencia
    int matriz[n ][n ];
    // Function call to create
    // Adjacency Matrix
    creaMatriz(matriz, arr);
    // Print Adjacency Matrix
    imprimeMatriz(matriz);
    return 0;
}