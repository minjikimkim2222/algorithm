#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num; // 5
    
    for (int i = 0; i < num; i++) // 총 5번
    {
  
        
            int temp = num-i-1;
            // cout << "temp : " << temp << '\n';
            while (temp--) // num-j-1번만큼,temp: 4 3 2 1 0
            {
                cout << ' ';
            } // i : 0 1 2 3 4, i+1 : 1 2 3 4 5
            // cout << "i : " << i << '\n';
            for (int j = 0; j < i+1; j++)
                cout << '*';
            cout << '\n';
    
    }
}

// 앞과 같은 논린데 더 깔끔한 부분 발췌
/*
int N;
cin >> N;

for (int i = 0; i < N; i++)
{
    int j = 0;
    for (; j < N-i-1; j++) cout << ' ';
    for (; j < N; j++) cout << '*';
    cout << '\n';
}

*/