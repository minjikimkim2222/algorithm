#include <stdio.h>

int main(void)
{
    int arr[3];
    int temp;
    for (int i = 0; i < 3; i++)
        scanf("%d", &arr[i]);
    if (arr[0] > arr[1])
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    if (arr[1] > arr[2])
    {
        temp = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;
    }
    if (arr[0] > arr[2])
    {
        temp = arr[2];
        arr[2] = arr[3];
        arr[3] = arr[2];
    }
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
}