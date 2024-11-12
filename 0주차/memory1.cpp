#include <bits/stdc++.h>

using namespace std;

int i;
int main(void){
    cout << &i << '\n';
    i = 5;
    cout << &i << '\n';
    return 0;
    // 0x10230c000 -- OS, 실행시간 등에 따라 메모리주소가 달라진다.
}