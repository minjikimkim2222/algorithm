// stack의 성질 : 가장 마지막의 들어온 것이, 가장 먼저 나온다! (가장 먼저 들어온거는 가장 나중에!)
/*
    string input : cin, getline()을 그냥 같이 쓰면, cin으로 인해 입력버퍼에 남아있던 개행문자가
    getline에서 개행만 읽어들여 문제 발생!
    따라서, cin.ignore()을 이용해 입력버퍼를 지우고, 엔터키를 제거한다.
*/ 
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    int count;
    string str;
    int stackSize;

    cin >> count;
    cin.ignore(); // 입력버퍼 비우기
    stack<char> st;

    while (count--){
        getline(cin, str);

        for (int i = 0; i <= str.length()-1; i++){
            
            if (i == str.length() - 1){
            st.push(str[str.length()-1]);
            }

            if (str[i] == ' ' || i == str.length()-1){
                stackSize = st.size();
                for (int j = 0; j < stackSize; j++){
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
        
            else {
            st.push(str[i]);
            }
        }
        cout << '\n';
    }
}