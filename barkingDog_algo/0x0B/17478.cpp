/* 솔직히 감이 잘 안 옴. 다시!
쫄지 말고, bar함수 틀부터 잡고, 재귀함수 종료 후에도 반복되는 애 있다면 써주면 됨.
재귀함수 틀 잡고[제일 큰 k 기준], 함수 정의 체계적으로 잡기
1. 함수 정의
2. base condition -> 반복이 종료되는 시점 관찰!
    "재귀함수는 자기 자신을 호출하는 함수라네, cnt == N"
3. 재귀식
    n = k -> bar(잘 들어보게.~ 물었어.)
    -> 
    n = k+1 -> bar(잘 들어보게. ~물었어.)
    하고 매번 재귀 완전 끝나고, ~라고 답변하겠지.

헷갈리면, "함수 기능별로 쪼개기!"
    -> 언더바 출력 함수, 문자열 출력 함수 구분
*/

#include <iostream>

using namespace std;
int N;

void bar(char* str, int stk)
{
    for (int i = 0; i < stk; i++) cout << "____";
    cout << str;
}

void solve(int cnt)
{
    bar("\"재귀함수가 뭔가요?\"\n", cnt);
    if (cnt == N)
        bar("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", cnt);
    else
    {
        bar("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", cnt);
        bar("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", cnt);
        bar("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", cnt);
        solve(cnt+1);
    }
    bar("라고 답변하였지.\n", cnt);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    solve(0);
}