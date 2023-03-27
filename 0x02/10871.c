#include <stdio.h>

int main(void)
{
    int N;
    int X;
    int array[10100];
    int value;

    scanf("%d %d\n", &N, &X);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value);
        array[i] = value;
        if (array[i] < X)
            printf("%d ", array[i]);
    }
    return (0);
}