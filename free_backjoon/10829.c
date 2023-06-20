#include <stdio.h>

void int_to_binary(long n);

int main(void)
{
    long n;
    scanf("%ld", &n);
    int_to_binary(n);    
}

void int_to_binary(long n)
{
    if ((n / 2) == 1)
    {
        printf("%ld", n / 2);
        printf("%ld", n % 2);
        //재귀 종결
    }
    else
    {
        int_to_binary(n / 2);
        printf("%ld", n % 2);
        // 재귀 
    }
}