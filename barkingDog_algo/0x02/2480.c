#include <stdio.h>

// 1차 시도 -> 틀린 코드
//  int main(void)
//  {
//      int arr[3];
//      int max;

//     scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
//     if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
//         printf("%d\n", (10000 + 1000 * arr[0]));
//     else if ((arr[0] != arr[1]) && (arr[1] != arr[2]))
//     {
//         max = arr[0];
//         for (int i = 0; i < 3; i++)
//         {
//             if (arr[i] > max)
//                 max = arr[i];
//         }
//         printf("%d\n", (max * 100));
//     }
//     else
//     {
//         if (arr[0] == arr[1] || arr[0] == arr[2])
//             printf("%d\n", (1000 + arr[0] * 100));
//         else
//             printf("%d\n", (1000 + arr[1] * 100));
//     }
// }

// 2차 시도 -> 더 껄끔한 분류로 생각하도록 노력
int main(void)
{
    int a, b, c;
    int max;

    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
        printf("%d\n", 10000 + a * 1000);
    else if (a == b || a == c)
        printf("%d\n", 1000 + a * 100);
    else if (b == c)
        printf("%d\n", 1000 + b * 100);
    else
    {
        if (a > b && a > c)
            printf("%d\n", a * 100);
        else if (b > c && b > a)
            printf("%d\n", b * 100);
        else
            printf("%d\n", c * 100);
    }
}