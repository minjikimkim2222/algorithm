#include <stdio.h>

int func1(int n)
{
    int i;
    int sum;

    i = 1;
    sum = 0;
    while (i <= n)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum = sum + i;
        }
        i++;
    }
    return (sum);
}

int main(void)
{
    printf("%d\n", func1(27639));
}