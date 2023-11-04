#include <iostream>

using namespace std;

int arr[101]; // 1~100번 바구니


int main(void)
{
    int n, m; // n개 바구니, m번 순서 변경
    int a, b; // a번째 바구니부터 b번째 바구니 순서를 역순으로 변경

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    
    while (m--){
        cin >> a >> b;
        if (a != b){
            for (int i = 0; i <= (b-a)/2; i++)
                swap(arr[a+i], arr[b-i]);
        }

    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}

