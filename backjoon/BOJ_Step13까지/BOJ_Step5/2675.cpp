#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int t;
    int repeatCount;
    string str;

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> repeatCount; // 5
        cin >> str; // /HTP
        for (int j = 0; j < str.length(); j++){
            for (int k = 0; k < repeatCount; k++){
                cout << str[j];
            }
        }
        cout << '\n';
    }
}