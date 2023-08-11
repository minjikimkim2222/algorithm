/*
다음은 선택정렬.
현재 위치에 들어갈 원소를 찾아서, 해당 위치와 교환하는 정렬.
*/
#include <iostream>

using namespace std;

void sort(int *p);


int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    n = 10;
    int arr[10] = {3, 2, 4, 5, 9, 7, 1, 543, 46, 0};

    sort(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << "\n";
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void sort(int *p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (p[i] > p[j])
                swap(p[i], p[j]);
        }
    }
}