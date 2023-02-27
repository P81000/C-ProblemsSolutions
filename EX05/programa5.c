#include <stdlib.h>
#include <stdio.h>
#define NMAX 1000
#define CMAX 1000000
 
int min(int x, int y) {return (x < y ? x : y);}
int max (int x, int y) {return (x > y) ? x : y;}
 
int main() 
{
    int N, C, T1, T2;
    scanf("%d %d %d %d", &N, &C, &T1, &T2);
    int i, j = 0, cost = 0, antena_atual;
 
    int *P = (int*)malloc(N* sizeof(int));
    for(i = 0; i < N; i++)
        scanf("%d", &P[i]);
    int *dp = (int*)malloc(N* sizeof(int));
    for(i = 0; i < N; i++)
        dp[i] = CMAX;
    int *dp1 = (int*)malloc(N* sizeof(int));
    
    int lower = min(T1, T2);
    int higher = max(T1, T2);
    dp[0] = 0;
    for(i = 0; i < N; i++)
    {  
        for(j = i; j < N; j++)
        {
            if(P[j] - P[i] == 0)
                dp[i] = lower;
            if(P[j] - P[i] <= lower)
                dp[i] = min(dp[i], dp[j - 1] + lower);
        } 
    }

    for(i = 0; i < N; i++)
        printf("%d ", dp[i]);

    system("PAUSE");
    return 0;
}

/*
5 20 2 3
2 5 8 11 15

    2   5   8   11  15
2   2   3   5   6   8

5       2   3   5   7    

8           2   3   5

11              2   3

15                  2


    1
4 20 12 9
1 2 3 13

    1   2   3   13
1   9   9   9   12

2       9   9   9

3           9   9

13              9

5 10 1 2
1 2 4 5 10

    1   2   4   5   10
1   1   2   3   5   6

2       1   2   3   5

4           1   2   3

5               1   2

10                  1
*/