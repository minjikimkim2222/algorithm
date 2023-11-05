#include <iostream>
#include <string> // find STL, 입력문자열 최초 등장 위치 반환

using namespace std;

int main(void)
{
    int alphabet[26]; // 각 알파벳 개수를 담는 배열
    string str;

    cin >> str;

    for (int i = 0; i < 26; i++)
        alphabet[i] = -1;
    
    for (int i = 0; i < str.length(); i++){
        alphabet[(str[i] - 96) -1] = str.find(str[i]);
    }
    for (int i = 0; i < 26; i++){
        cout << alphabet[i] << ' ';
    }
}