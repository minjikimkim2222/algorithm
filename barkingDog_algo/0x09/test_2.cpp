#include <iostream>

using namespace std;

int main(void)
{
    string board[100];

    // 행 :2, 열 : 3
    for (int i = 0; i < 2; i++)
    {
            cin >> board[i];
    }

    for (int i = 0; i < 2; i++){
 
            cout << board[i]<< ' ';
        
        cout << "\n";
    }
}