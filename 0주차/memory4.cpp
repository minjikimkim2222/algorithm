#include <bits/stdc++.h>

using namespace std;

int a[3] = {1,2,3};

int main(void){
    int* c = a; // 배열이름 a가 &a[0]처럼 쓰인다!

    cout << c << '\n';
    cout << &a[0] << '\n';
    cout << c + 1 << '\n';
    cout << &a[1] << '\n';
}