/*
1. 문제의도에 집중해서 결국 핵심은 무엇을 구현하는 것일까?
    -> stack의 응용 : 괄호쌍 알고리즘, LIFO! 구현

2. 구현 -> "간단"하게 경우를 4가지로 나눠서 생각해보자!

3. 변수를 쪼개자! 

4. 솔직히 그냥 거의 참고한 코드..

5. 근데 왜 stack이랑 str을 전역변수에 넣어야 성공하는데?????????????
*/

#include <iostream>
#include <stack>

using namespace std;

stack<char> st;
string s;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // string s;
    cin >> s;
   // stack<char> st;

    int sum = 0; // 리턴값, 총 괄호값
    int num = 1; // 곱할 값

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            num *= 2;
            st.push(s[i]);
        }
        else if (s[i] == '['){
            num *= 3;
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            if (st.empty() || st.top() != '('){
                cout << "0\n";
                return (0);
            }
            if (s[i-1] == '(') sum += num;
            st.pop();
            num /= 2; // () 쌍 없어졌으니 없애기!
        }
        else if (s[i] == ']'){
            if (st.empty() || st.top() != '['){
                cout << "0\n";
                return (0);
            }
            if (s[i-1] == '[') sum += num;
            st.pop();
            num /= 3;
        }
    }
    if (st.empty()) cout << sum << '\n';
    else cout << "0\n";
}
