#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1025
 
// Inicialização da matriz
void initMat(int **mat) 
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            mat[i][j] = 0;
}
 
// Insere na matriz a qnt de usuarios
void insertMat(int **mat, int *X, int *Y, int user) 
{
    int i, j;

    for (i = X[0]; i <= X[1]; i++)
        for (j = Y[0]; j <= Y[1]; j++) 
        {
            if (i >= 0 && i < MAX && j >= 0 && j < MAX)
            mat[i][j] += user;
        }
}
 
// Procura na matriz a menor coordenada com maior numero de usuários
void searchMat(int *total, int *x, int *y, int **mat) 
{
    int i, j;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++) 
        {
            if (mat[i][j] > *total) 
            {
                *total = mat[i][j];
                *x = i;
                *y = j;
            }
        }
}
 
int main(void) 
{
    int i;          // Variaveis auxiliares
    int X[2], Y[2]; // posX - d -> X[0] e posX + d -> X[1]; posY - d -> Y[0] e
                    // posY + d -> Y[1]
    int d, n, posX, posY, user; // Variáveis de entrada
    int total = 0, x, y;        // Variáveis de saída



    // Inicialização da matriz
    int **mat = (int**)malloc(MAX * sizeof(int*));
    for(i = 0; i < MAX; i++)
        mat[i] = (int*)malloc(MAX * sizeof(int));
    initMat(mat);
    //

    scanf("%d", &d);
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d %d %d", &posX, &posY, &user);
        X[0] = posX - d;
        X[1] = posX + d;
        Y[0] = posY - d;
        Y[1] = posY + d;
        insertMat(mat, X, Y, user);
    }

    searchMat(&total, &x, &y, mat);

    printf("%d %d %d", x, y, total);

    // Free mat
    for (i = 0; i < MAX; i++)
        free(mat[i]);
    free(mat);
    //

    system("PAUSE");

    return 0;
}