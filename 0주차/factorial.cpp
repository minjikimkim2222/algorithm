#include "bits/stdc++.h"

using namespace std;

// 1. 재귀로 팩토리얼
int factorial(int n){
    if (n <= 1){
        return 1;
    }
    return n * factorial(n-1);
}

// 2. 굳이 재귀 말고, 반복문도 된다면, 반복문도!
int factorial2(int n){
    int ret = 1;

    if (n == 1 || n == 0)
        return 1;
    
    for (int i = 2; i <= n; i++){
        ret *= i;
    }

    return ret;
}

int main(void){
    int input;
    cout << "input : " << '\n';
    cin >> input;
    cout << "result1 : " << factorial(input) << '\n';
    cout << "result2 : " << factorial2(input) << '\n';
}