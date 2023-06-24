/*
1. 출제의도 파악!
쫄지 말고, 문제의 '본질'에 집중해서, 최대한 간단하게 풀려고 노력!
 -> 그럴려면 문제의 본질이 자료구조인 "스택"의 활용임을 일단 집중!
 -> 관찰 중, 수많은 괄호를 보관할 자료구조 고민(배열?연결리스트?스택?큐?덱?)
     -> 근데, 가장  최근의 괄호가 제일 먼저 대응되는 구조임! -> LIFO
2. 핵심[본질]
핵심 : )를 만났다, 이때
	바로 앞의 괄호가 ( 이면, ‘레이저’ 라서 (이 pop된다. 그 후 그 스택 안에 남아있는 (의 개수가 잘린다! 
	바로 앞의 괄호가 ) 이면, ‘쇠막대기’ 라서 pop되며 대응되는 (이 pop되며 스택 개수가 줄어든다. (쇠막대기 개수가 줄어든다)

3. 구현 [test.cpp에서도 보듯이]
    1) string s는 배열처럼 인덱스 당연히 가능
    s[0], s[1]

    2) 물론 string s는 size 멤버함수도 가진다!!
*/

#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    int count = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            if (s[i-1] == '(') // 레이저
            {
                st.pop();
                count += st.size();
            }
            else if (s[i-1] == ')') // 쇠막대기
            {
                st.pop();
                count++; // 막대 개수가 1개 줄어듦, 1개 잘려진 것과 동일한 것[이를 간과!]
            }
        }
    }
    cout << count << '\n';
}