#include <bits/stdc++.h>

using namespace std;

int T;
string s;

// cin으로 입력받은 T번만큼, getline 할 때
int main(void){
    cin >> T;

    string bufferflush;
    getline(cin, bufferflush);

    for (int i = 0; i < T; i++){
        getline(cin, s);
        cout << s << '\n';
    }

    return 0;
}