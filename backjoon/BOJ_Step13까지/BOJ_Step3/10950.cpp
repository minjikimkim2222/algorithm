#include <iostream>

using namespace std;

int main(void)
{
    int t;
    int a,b;

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a >> b;
        cout << a + b << '\n';
    }
}