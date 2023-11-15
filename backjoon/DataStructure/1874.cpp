/*
풀이
- 입력한 값까지 수를 순서대로 push한다 (스택)
- 스택에 들어간 마지막 숫자와 입력한 숫자가 같다면 pop한다
  아니면 불가능!
- array 대신 vector를 씀으로써, index를 신경쓸 필요가 없어져서 편리해짐.!

-> 이것처럼 관찰을 하고, 논리를 간단하게 작성할 것!!
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    stack<int> st;
    vector<char> result; 

    int inputNum;
    int cnt;
    cin >> n;

    cnt = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> inputNum;

        while (cnt <= inputNum){
            st.push(cnt);
            cnt++;
            result.push_back('+');
        }

        if (st.top() == inputNum){
            st.pop();
            result.push_back('-'); 
        }
        else{
            cout << "NO\n";
            return (0);
        }
    }

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }

}