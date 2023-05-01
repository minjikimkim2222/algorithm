// 첫번째 시도 -> 시간 초과로 실패..브루스포스로 했음
// #define MAX 100001
// #include <stdio.h>

// int main(void)
// {
//     int arr[MAX];
//     int n;
//     int x;
//     int count;

//     scanf("%d", &n);
//     for (int i= 0; i<n; i++)
//         scanf("%d", &(arr[i]));
//     scanf("%d", &x);
//     count = 0;
//     for (int i = 0; i<n; i++)
//     {
//         for (int j=i+1; j<n;j++)
//         {
//             if (arr[i] + arr[j] == x)
//             {
//                 count++;
//                 break;
//             }
//         }
//     }
//     printf("%d\n", count);
// }

//두번째 시도 -> 1) 오름차순 정렬 + 2)binary search 이용
#define MAX 100001
#include <iostream>
#include <algorithm> //sort함수 -> nlogn기반 sort함수, sort(begin, end)
/* sort(begin, end)
default : asecding
desc >> sort(begin, end, desc) ; begin, end 모두 주소값
*/

using namespace std;
int binary_search(int arr[], int size, int x, int count);

int main(void)
{
    int arr[MAX];
    int n;
    int x;

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> x;

    sort(arr, arr + n); // 1. 오름차순 정렬 완료
    // 2. binary search로 원하는 쌍 구하기
    int count = 0;
    count = binary_search(arr, n, x, count);
    cout << count / 2;
}

int binary_search(int arr[], int size, int x, int count)
{
    for (int i = 0; i < size; i++)
    {
        int low = 0; // low = i로 하면 앞에 있는 애를 뻬서, 뭔가 예외 상황 발생하는 듯..걍 다 구하고 나누기 2
        int key = x - arr[i]; //low 대신 i로 바꿔야 했음, key의 의미를 생각하면 됨.
        int high = size - 1; //high 위치
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (key == arr[mid]){
                count++;
                break;
             }
            else if (key < arr[mid])
                high = mid - 1;
            else if (key > arr[mid])
                low = mid + 1;
        }
    }
    return (count);
}