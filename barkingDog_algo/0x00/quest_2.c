#include <stdio.h>

int func2(int arr[], int N)
{
    int i;
    int j;

    i = 0;
    while (i < N)
    {
        j = i + 1;
        while (j < N)
        {
            if (arr[i] + arr[j] == 100)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int main(void)
{
    int arr[4] = {4, 13, 63, 87};
    printf("%d\n", func2(arr, 4));
}