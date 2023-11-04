#include <iostream>
// #include <climits>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    int arr[1000000];
    int min;
    int max;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // min = 1000001;
    // max = -1000001;
    // for (int i = 0; i < N; i++)
    // {
    //    if (arr[i] > max){
    //         max = arr[i];
    //    }

    //    if (arr[i] < min){
    //         min = arr[i];
    //    }
    // }
    // cout << min << ' ' << max ;

    // 오름차순 정렬 후, 최소 최대  출력 !
    sort(arr + 0, arr + N); // 0 ~ N-1 범위 정렬 

    cout << arr[0] << ' ' << arr[N - 1];

}