#include <bits/stdc++.h>

using namespace std;

char returnChar(){
    return 'r';
}

void compareNullAndZero(){
    char a = '\0';
    char b = 0;
    char c = NULL;

    if (a == b) cout << "\\0 and 0 is equal" << '\n';
    if (b == c) cout << "0 and NULL is equal" << '\n';

}


int main(void){
    char c = 'a';
    cout << c << '\n';
    cout << returnChar() << '\n';
    compareNullAndZero();

    return 0;
}