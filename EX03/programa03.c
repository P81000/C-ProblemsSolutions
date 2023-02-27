/*Pedro Masteguin - 158471
  Problema 3 
*/

#include <stdlib.h>
#include <stdio.h>


void init_vet(int *vet, int size)
{
    for(int i = 0; i < size; i++)
        vet[i] = -1;
}

void print_vet(int *vet, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", vet[i] + 1);
    printf("\n");
}

/*--------- BACKTRACK ---------- */
void process_solution(int *vet1, int *vet2, int n)
{
    int i;
    int aux = 1;
    for (i = 0; i < n; i++)
        if (vet1[i] != -1 && vet2[i] + 1 != vet1[i])
            aux = 0;
        
    if(aux == 1)
        print_vet(vet2, n);
}

void construct_candidates(int *vet2, int start, int end, int *candidates, int *n_candidates)
{
    /* Construct Candidates */
    int in_perm[end], i;
    init_vet(in_perm, end);

    for(i = 0; i < start; i++)
        in_perm[ vet2[i] ] = 1;

    for(i = 0; i < end; i++)
    {
        if(in_perm[i] != 1)
        {
            candidates[*n_candidates] = i;
            (*n_candidates)++;
        }
    }
}

void backtracking(int *vet1, int *vet2, int start, int end)
{
    int i;
    if(start == end)
        process_solution(vet1, vet2, end);
    else
    {
        int n_candidates = 0;
        int candidates[end];
        
        construct_candidates(vet2, start, end, candidates, &n_candidates);
        for(i = 0; i < n_candidates; i++)
        {
            vet2[start] = candidates[i];
            backtracking(vet1, vet2, start + 1, end);
        }
    }
}


int main(void)
{
    int n, m, x, y; //Variaveis de entrada
    int i, j = 0, tam; //Variaveis auxiliares
    scanf("%d %d", &n, &m);
    tam = n - m;
    int vet1[n], vet2[n], vet3[n - m]; //vet1 = vetor de entrada; vet2 = vetor de saída; vet3 = vetor contendo apenas os candidatos

    /* Inicializa os vetores */
    init_vet(vet1, n);
    init_vet(vet2, n);
    init_vet(vet3, n);

    /* Le os valores de entrada */
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        vet1[y - 1] = x;
    }
    /* Candidates */
    for(i = 0; i < n; i++)
        if(vet1[i] != 0)
        {
            vet3[j] = vet1[i];
            j++;
        }

    /* Saída */
    backtracking(vet1, vet2, 0, n);
    
    system("PAUSE");
    return 0;
}