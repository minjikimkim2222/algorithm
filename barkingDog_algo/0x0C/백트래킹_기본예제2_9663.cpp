/*
N-QUEENS 문제의 쟁점
1. 한 행당, 1개의 퀸을 두는 것을 전제로 한다.
2. N*N 배열을 만들 필요 없이, 크기가 N인 일차열 배열을 만든 후, 각 행의 "몇 번째 열"에 퀸이 있는지 저장하는
방식으로 풀 수 있다.

*/

#include <iostream>
#include <cstdlib> // int형 절댓값 함수
using namespace std;

int cnt;
int n; // N*N 배열의 n-queens 문제를 풀자!
int queen_col[14]; // 각 행의 몇 번째 "열"에 퀸이 있는지!

bool check_condition(int row) // row(행)만 전달해줘도, 이미 queen_col에 열이 채워져 있을 거니, 상관없음
{
    for (int i = 0; i < row; i++)
    {
        if (queen_col[i] == queen_col[row]) // i == row는 애초에, 한 행에 한 퀸만 놓는다는 전제로 짰으니 굳이 안 해줘도 됨!
            return (false);
        if (row - i == abs(queen_col[row] - queen_col[i])) // 기울기가 1이거나 -1
            return (false);
    }
    return (true);
}

void n_queen(int row) // row행에 해당하는 숫자 채우기!
{
    if (n == row) // n번째 행까지 n개의 퀸을 놓는 하나의 경우의 수 완료!
    {
        cnt++;
        return ;
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            queen_col[row] = col;
            if (check_condition(row) == true)
                n_queen(row + 1); // 현재 행, 열 위치가 퀸의 위치로 올바르다면, 다음 행의 열도 채우기
            // *** 현재 행, 열 위치가 퀸의 위치로 올바르지 않다면, "이어서 반복문 진행"
        }
        /*
        <<핵심 구조>>를 깨달았다!!!
        조건에 맞고, 내가 원하는 답을 찾았다면, 다음 단계 호출! [더 깊숙이 들어간다]-> n_queen()호출!
        조건에 틀렸다면, 다른 선택지를 골라(for문 이어서), 해당 선택지는 조건에 맞는지 검사할 것!
        */
    }
    // for문 다 돌아도, 특정 row에 만족되는 열을 찾지 못했다! -> 해당 n_queen()함수 리턴 -> 되돌아간다, 백트래킹!

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    n_queen(0);
    cout << cnt;

}