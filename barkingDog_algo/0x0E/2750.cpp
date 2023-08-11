// 기초정렬 중 버블정렬 이용!
#include <iostream>

using namespace std;
int n;
int arr[1002];

void sort(int arr[]);
void swap(int *p, int *q);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// 5 2 3 4 1 
void sort(int arr[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}