// 7569 2차원 배열, 3차원 배열
#include <iostream>

using namespace std;

// int arr2[2][3];
// int arr3[3][2][4];
// int main(void)
// {
//     int num = 0;

//     for (int i = 0; i < 2; i++){
//         for (int j = 0; j < 3; j++){
//             arr2[i][j] = num++;
//             cout << arr2[i][j] << ' ';
//         }
//         cout << "i : " << i << " , \n";
//     }

//     cout << "\n\n3차원 배열 시작이다\n\n";
//     num = 0;
//     for (int h = 0; h < 3; h++){
//         cout << "h : " << h << " >>";
//         for (int i = 0; i < 2; i++){
//             for (int j = 0; j < 4; j++){
//                 arr3[h][i][j] = num++;
//                 cout << arr3[h][i][j] << ' ';
//             }
//             cout << "\n";
//         }
//         cout << "\n\n";
//     }
// }

int board[10][10][10];
int m,n,h;

int main(void){
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> board[i][j][k];
            }
        }
    }

    for (int i = 0; i < h; i++){
        cout << "h : " << i << "  >> ";
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cout << board[i][j][k];
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    cout << "board[1][1][2] : " << board[1][1][2] << '\n'; 
    
}