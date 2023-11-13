/*
소문자 알파벳과 대문자 알파벳 차이 = 32
A와 Z의 차이 = 25

'A' = 65, 'Z' = 90
'a' = 90, 'z' = 122

a = 90 - 65 = 25 .. -> 대문자를 전부 소문자로 바꾸자. 

A = 0, B = 1 ... [ ch - 65 ]
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string str;
    int arr[26];
    int max;
    int count = 0;

    cin >> str;
    for (int i = 0; i < str.length(); i++){
        str[i] = toupper(str[i]);
    }

    for (int i = 0; i < 26 ; i++){
        arr[i] = 0;
    }

    for (int i = 0; i < str.length(); i++){
        arr[str[i] - 65]++;
    }

    sort(arr, arr + 26);
    max = arr[25];

    for (int i = 0; i < 26; i++){
        if (max == arr[i]) count++; // max개수 나올때마다 count
    }

    if (count != 0)
        cout << "?";
    else {
        cout << (char)(max + 65);
    }
    // A = 0, B = 1 ... [ ch - 65 ]
}
