#include <stdio.h>

int func4(int n)
{
    int val;

    val = 1;
    while (2 * val <= n)
        val *= 2;
    return (val);
}