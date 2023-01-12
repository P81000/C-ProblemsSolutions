#include <stdlib.h>
#include <stdio.h>
#define NMAX 1000
#define CMAX 1000000

int min(int x, int y) {return (x < y ? x : y);}

int main() 
{
    int N, C, T1, T2;
    scanf("%d %d %d %d", &N, &C, &T1, &T2);
    int i, j, costT1, costT2;

    int *P = (int*)malloc(N* sizeof(int));
    for(i = 0; i < N; i++)
        scanf("%d", &P[i]);
    
    int *dp = (int*)malloc(N* sizeof(int));
    for(i = 0; i < N; i++)
        dp[i] = CMAX;
    
    dp[0] = 0;
    for(i = 1; i < N; i++)
    {
        for(j = 0; j < i - 1; j++)
        {
            costT1 = T1 * (P[i] - P[j]) ;
            costT2 = T2 * (P[i] - P[j]);
            dp[i] = min(dp[i], min(dp[j] + costT1, dp[j] + costT2));
        }
    }
    
    for(i = 0; i < N; i++)
        printf("%d ", dp[i]);
    

    return 0;
}