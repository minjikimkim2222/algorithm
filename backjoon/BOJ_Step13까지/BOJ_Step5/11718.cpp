#include <iostream>
#include <string>

// eof는 fstream 객체가 EOF(더 이상 읽을 값이 없다)이면, 참값 반환
using namespace std;

int main(void)
{
    string str;

    while (true){
        getline(cin, str);
        if (cin.eof() == true)
            break ;
        cout << str << '\n';
    }
}