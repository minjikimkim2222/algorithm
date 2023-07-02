// #include <iostream>

// using namespace std;

// int idx[9];
// int arr[9];

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     for (int i = 0; i < 9; i++){
//         cin >> idx[i]; // orginal
//         arr[i] = idx[i]; // edit
//     }
//     // input complete

//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = i+1; j < 9; j++) // j가 한 칸 뒤 , j범위를 9까지로!
//         {
//             if (arr[i] > arr[j]){
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     cout << arr[8] << '\n';
//     for (int i = 0; i < 9; i++){
//         if (idx[i] == arr[8])
//             cout << i + 1<< '\n';
//     }




// }

/*
앞선 1차 시도는
1) 탐색을 2중 for문을 썼고, 
2) idx를 찾기 위해 복사본과 원본을 써서 순수하게 비교함.
더 현명한 방법? -> 입력과 동시에 간단하게 비교해도 됨. 배열 안 써도 당근 쌉가능.
오히려 그냥 max를 입력받을 때마다 갈아끼고, idx도 갱신하면 됨
*/

#include <iostream>

using namespace std;

int n, maxvalue, maxidx;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 10; i++) // idx랑 똑같이 하게 위해
    {
        cin >> n;
        if (maxvalue < n)
        {
            maxvalue = n;
            maxidx = i;
        }
    }
    cout << maxvalue << "\n" << maxidx;
}