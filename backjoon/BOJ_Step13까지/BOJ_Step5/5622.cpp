// 초 = 해당 숫자 + 1 
// 알파벳 -> 해당 숫자

/*
보다 효율적인 2번째 방법 존재.
애초에 array에 각 알파벳에 대한 시간을 미리 설정할 것!
int time[26] =  { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
*/

// #include <iostream>

// using namespace std;

// string input;
// int number[10];

// void divide();
// int main(void)
// {
//     int totalTime = 0;

//     cin >> input;
//     for (int i = 2; i <= 9; i++){
//         number[i] = 0; // 2, 3, 4, 5, 6, 7, 8, 9
//     }

//     divide();
    
//     for (int i = 2; i <= 9; i++){
//         if (number[i] != 0)
//             totalTime += (i+1) * number[i];
//     }
//     cout << totalTime;


// }

// void divide()
// {
//     for (int idx = 0; idx < input.length(); idx++){
//         if (input[idx] >= 'A' && input[idx] <= 'C')
//             number[2]++;
//         else if (input[idx] >= 'D' && input[idx] <= 'F')
//             number[3]++;
//         else if (input[idx] >= 'G' && input[idx] <= 'I')
//             number[4]++;
//         else if (input[idx] >= 'J' && input[idx] <= 'L')
//             number[5]++;
//         else if (input[idx] >= 'M' && input[idx] <= 'O')
//             number[6]++;
//         else if (input[idx] >= 'P' && input[idx] <= 'S')
//             number[7]++;
//         else if (input[idx] >= 'T' && input[idx] <= 'V')
//             number[8]++;
//         else if (input[idx] >= 'W' && input[idx] <= 'Z'){
//             number[9]++;
//         }
//     }
//     return ;
// }

/*
보다 효율적인 2번째 방법 존재.
애초에 array에 각 알파벳에 대한 시간을 미리 설정할 것!
int time[26] =  { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    int time[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };   
    int totalTime;

    cin >> str;
    totalTime = 0;

    for (int i = 0; i < str.length(); i++){
        totalTime += time[str[i] - 65];
    }
    cout << totalTime;
}