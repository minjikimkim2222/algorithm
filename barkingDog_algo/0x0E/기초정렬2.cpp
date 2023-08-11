/*
버블정렬 : 앞에서부터 인접한 두 원소를 보면서, 앞의 원소가 뒤의 원소보다 클 경우 자리를 바꾼다.
그러면 자연스럽게 제일 큰 것부터 오른쪽에 차곡차곡 쌓이게 된다.

**제일 오른쪽부터 정렬이 고정되니까, int j = 0부터!
*/

#include <iostream>

using namespace std;

void sort(int arr[]);
void swap(int *p, int *q);
int n = 5; // 배열원소 개수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5] = {2,13,6,4,-2};
    sort(arr);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// n = 5
// i = 0 -> j = 0,1,2,3
// i = 1 -> j = 0,1,2
void sort(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++){ // j가 0부터 시작함을 ! ! ! ! ! 
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}