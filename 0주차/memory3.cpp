#include <bits/stdc++.h>

using namespace std;

int main(void){
    string a = "abcda";
    string* b = &a;

    cout << b << '\n'; // 0x16d01efa0
    cout << *b << '\n'; // abcda

    return 0;
}