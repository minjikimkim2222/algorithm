#include <stdio.h>

int main(void)
{
    int arr[3];
    int idx;
    int tmp;

    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    idx = 1;
    for (int i = 0; i < 2; i++)
    {
        if (arr[idx] < arr[idx - 1])
        {
            tmp = arr[idx];
            arr[idx] = arr[idx - 1];
            arr[idx - 1] = tmp;
        }
        idx++;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}