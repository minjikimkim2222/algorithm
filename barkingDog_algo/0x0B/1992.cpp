/*
>> 재귀 종료 조건을 잘못 설정해 다 꼬임, 거의 배껴서 좀 슬프네요
1. 재귀

2. 함수의 정의식 !
    int solve(n,a,b) // n*n배열(n), x 시작좌표(a), y 시작좌표(b)
    -> x좌표 : a ~ a+n, y좌표 : b ~ b+n 까지 모두 같은 숫자면, 해당 숫자를 '출력'하는 함수!

3. 구현 시 주의할 점들.
    1. 재귀 종료 조건 고민 -> 1*1 배열 크기일 때, 종료일까, 해당 2차원 배열의 숫자가 모두 같다면인가?
        >>>> 재귀함수 종료 조건은 "재귀가 무한히 일어나는 것"을 방지하기 위해 있음.
        결국, 1*1 배열 크기일 때 종료를 해야, 재귀를 반드시 종료시킬 수 있음을 기준으로 생각!

*/

#include <iostream>

using namespace std;

char paper[70][70];

void solve(int n, int a, int b)
{
    if (n==1)
    {
        cout << paper[a][b];
        return ;
    }
    
        // zero, one 변수를 이용해 쿼드트리가 모두 같은 수로 되어 있는지 체크!
        // 체크결과, 쿼드트리가 모두 같은 수라면, 해당 수로 출력하게 한다.
        // 단, 모두 같은 수로 이루어지지 않았다면, 각 사분면을 재귀적으로 호출하여 해결해나간다.
    bool zero = true;
    bool one = true;

    for (int i = a; i < a+n;i++){
        for (int j = b; j <b+n; j++){
            if (paper[i][j] == '1')
                zero = false;
            else
                one = false;
        }
    }
    if (zero == 1)
        cout << 0;
    else if (one == 1)
        cout << 1;
    
    else{
        cout << "(";
        int half = n / 2;
        solve(half, a, b); // 1사분면
        solve(half, a, b+half); // 2사분면
        solve(half, a+half, b); // 3사분면
        solve(half, a+half, b+half); // 4사분면
        cout << ")";
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];

    solve(n,0,0);

}