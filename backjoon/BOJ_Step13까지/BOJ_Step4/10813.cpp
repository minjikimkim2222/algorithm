#include <iostream>

using namespace std;

int arr[102];
void swap(int i, int j);

int main(void)
{
    int n, m;
    int i, j;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
 
    for (int count = 0; count < m; count++)
    {
        cin >> i >> j;
        swap(i,j);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}

void swap(int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}