#include <stdio.h>

int func3(int n)
{
    int i;

    i = 0;
    if (n < 0)
        return (0);
    else
    {
        while (i < n / 2)
        {
            if (i * i == n)
                return (1);
            i++;
        }
    }
    return (0);
}

int main(void)
{
    printf("%d\n", func3(693953651));
}