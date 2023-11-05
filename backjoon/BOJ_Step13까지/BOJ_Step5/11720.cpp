// 이전 문제에서 아스크코드를 준 이유가 있구나
#include <iostream>

using namespace std;

int main(void)
{
    char ch;
    int sum = 0;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ch;
        sum = sum + (ch - 48);
    }
    cout << sum;
}