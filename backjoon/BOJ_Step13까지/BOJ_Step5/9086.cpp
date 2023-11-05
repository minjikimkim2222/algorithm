#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int t;
    string str;

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> str;
        if (str.length() == 1)
            cout << str << str << '\n';
        else{
            cout << str[0] << str[str.length() - 1] << '\n';
        }
    }
}