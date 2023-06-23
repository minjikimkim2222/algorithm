// 핵심 규칙을 발견할 것 >> "pop하는 순서임, pop을 다 하고 나면 실행이 끝남"
// 단, 제발 specfic말고 예시 관찰하고 "일반화된 규칙"을 도출할 것!

// 1. "비교"하는 애가 뭐랑 뭔지! 정확하게 "변수로" 생각 <<< 이걸 습관화!
    // >> 비교할 수 있는 후보가 뭐랑 뭐가 있는지!

// 2. string 자료형을 output으로 활용하기!

// 3. 헤더파일 <bits/stdc++.h>헤더랑, +=를 쓸 것!(안 그럼 타임 아웃 에러 남 ㄷㄷ)

#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    stack<int> st;
    int cnt = 1; // 오름차순 숫자
    string ans;
    while (n--)
    {
        int t;
        cin >> t; // 매번 입력숫자
        while (cnt <= t){
            st.push(cnt);
            cnt++;
            ans = ans + "+\n";
        }
        if (st.top() != t){
            cout << "NO\n";
            return (0);
        }
        st.pop();
        ans = ans + "-\n";
    }
    cout << ans;
}