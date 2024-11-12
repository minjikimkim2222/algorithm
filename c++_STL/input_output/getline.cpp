#include <bits/stdc++.h>

using namespace std;

string str;
string str2;
int main(void){
    // 1. default getline (문자열 끝을 '\n'으로 인식)
    getline(cin, str);
    cout << str << '\n';

    // 2. getline()은 문자열 종결문자를 지정할 수 있다.
    getline(cin, str2, '.');
    cout << str2 << '\n';
    
    return 0;
}