/*Pedro Masteguin - 158471 - Problema 4 */
#include <stdio.h>
#include <stdlib.h>
int get_count(int entry, int count)
{
    count++;
    int index = 0, diff;
    if(entry == 0)
        return count;
    else
    {
        index = log2(entry);
        index++;
        if(abs(pow(2, index) - entry) < abs(pow(2, index - 1) - entry))
            diff = abs(pow(2, index) - entry);
        else
            diff = abs(pow(2, index - 1) - entry);
        return get_count(diff, count);
    }
}
int main(void) 
{
    int N;
    scanf("%d", &N);
    printf("%d", get_count(N, 0) - 1);

    system("PAUSE");
    return 0;
}