/*
놓쳤던 것 => string 배열을 이용해서 비교하면 됨.
    -> string str[50];
        str[0][1] -> 첫번째 str이 들어있는 배열의 idx 0에서, 첫번째 문자

생각보다 어려움을 겪어, 문제 답을 확인했음..ㅜ
*/

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string str[50];

    for (int i =0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < str[0].size(); i++)
    {
        char c = str[0][i];
        for (int j = 1; j < n; j++)
        {
            if (c != str[j][i]){
                c = '?';
                // break;
            }
        }
        cout << c;
    }
}