#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    int i, j, k;
    int arr[101]; // n개의 바구니

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        arr[i] = 0;
    for (int count = 0; count < m; count++)
    {
        cin >> i >> j >> k;
        for (int count2 = i; count2 <= j; count2++)
        {
            arr[count2] = k;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}