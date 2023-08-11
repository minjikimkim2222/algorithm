/*
arr[st:en] 표현 : 왼쪽 구간은 포함, 오른쪽 구간은 제외
    예) arr[2:5] => arr[2], arr[3], arr[4]
즉, arr[st:en] => arr[st], arr[st+1], arr[en-1]까지

merge 함수 : 
arr[st:en]을 정렬하는 함수. => 피벗 관련(11728 코드) -> "정렬된 두 개의 배열을 합친다."
mid = (st+en) / 2라고 할 때, arr[st:mid]와 arr[mid:en]이 정렬되어 있을 때,
arr[st:en]를 정렬하는 것. 즉, 2개의 "정렬된" 배열을 합치는 걸 구현하는 함수

merge_sort함수 :
arr[st:en]을 정렬하는 것.
*/

#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[10]; //merge함수에서 리스트 2개를 합친 결과를 임시로 저장할 변수

void merge(int start, int end) // 앞서 구현한 피벗 관련(11728 코드!)
{
    int mid = (start + end ) / 2;
    int lidx = start;
    int ridx = mid;

    for (int i = start; i < end; i++)
    {
        if (ridx == end) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = start; i < end; i++)
        arr[i] = tmp[i];
}
void merge_sort(int start, int end)
{
    if (start + 1 == end)
        return ; // 길이가 1인 경우
    int mid = (start + end) / 2;

    merge_sort(start, mid); // arr[start : mid]정렬
    merge_sort(mid, end); // arr[mid : end] 정렬
    merge(start, end); // arr[st:mid]와 arr[mid : en]을 합친다.
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    merge_sort(0,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}