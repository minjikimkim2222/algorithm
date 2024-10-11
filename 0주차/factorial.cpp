#include "bits/stdc++.h"

using namespace std;

int factorial(int n){
    if (n <= 1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(void){
    int input;
    cin >> "input : " >> input >> '\n';
    cout << "result : " << factorial(input) << '\n';
}