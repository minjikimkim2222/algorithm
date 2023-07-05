/*
크기순서 거꾸로가 아니라, 그냥 진짜 index 역순으로
*/

#include <iostream>

using namespace std;
int arr[21];

void sort(int start, int end)
{
   int mid = (start + end) / 2;
   for (int i = 0; i < (mid-start+1); i++)
   {
        int temp = arr[start+i];
        arr[start+i] = arr[end-i];
        arr[end-i] = temp;
   }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 21; i++)
        arr[i] = i;
    
    for (int i = 0; i < 10; i++)
    {
        int x, y;
        cin >> x >> y;
        sort(x,y);
    }

    for (int i = 1; i < 21; i++)
        cout << arr[i] << ' ';
}