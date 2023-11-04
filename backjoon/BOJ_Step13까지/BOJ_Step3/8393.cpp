#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int sum;

    cin >> n;
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << sum;
    return (0);
}