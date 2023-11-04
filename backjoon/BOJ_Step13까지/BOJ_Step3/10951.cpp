#include <iostream>

using namespace std;

// eof는 fstream 객체가 EOF을 만다면 상수 -1로써 참값을 반환한다.
int main(void)
{
    int a,b;

    while (1)
    {
        cin >> a >> b;
        if (cin.eof() == true)
            break;
        cout << a + b << '\n';
    }

}