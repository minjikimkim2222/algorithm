/*
1. 입력 -> cin VS getline함수
    1) cin = 공백 이전까지만 입력받음. ex)입력 : "hello world", 출력 : "hello"
          왜냐면, 공백문자로 입력을 구분함!
   2)  getline함수 == [공백을 포함한 string의 입력!!]
        getline(istream& is, string str)
            ex) getline(cin, string)
            -> cin으로부터 입력받아, 공백을 포함한 문자열을 str에 입력받음 [한줄씩!]

2. 조건 작성 -> 확실한 여집합 이용[확실히 안 되는 조건을 if문에, 그 외에 되는 건 그럼 else겠지!]

3. 변수 선언과 초기화 위치 설정 헷갈리지 말 것!
*/
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string str;
        getline(cin, str);
        bool isvalid = true; // 한 문장에 대한 참값을 리턴해야 되니깐!
        stack<char> st;

        if (str == ".")
            break; // while문 종료조건 -> ok
        for (auto c : str){
            if (c == '(' || c == '['){ //  여는 괄호
                st.push(c);
            }
            else if (c == ')'){
                if (st.empty() || st.top() != '('){
                    isvalid = false;
                    break;
                }
                // 맞는 경우
                st.pop();
            }
            else if (c == ']'){
                if (st.empty() || st.top() != '['){
                    isvalid = false;
                    break;
                }
                st.pop();
            }
        }
    if (!st.empty()) isvalid = false;
    if (isvalid == true) cout << "yes\n";
    else cout << "no\n";

    }
}