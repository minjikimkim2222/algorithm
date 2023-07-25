/*
1. 3^7 = 2187이라 그냥 2200으로 배열 크기 잡음

2. 같은 과정 반복하다가 종료하는 알고리즘 => 재귀
    + 제일 큰 k에서의 수학적 귀납법 생각
    -> n = k일 때, if (n=k일 때 종이의 수가 모두 같은지)
                {
                    같다면, 그 종이 개수를 세서 각 변수에 저장
                }
                else 
                {
                    n = k/3 재귀호출
                }
    -> 따라서 k일 때 종이의 개수 같으면 센다면, k/3일 때도 종이의 개수가 같으면 셀 수 있다

3. 구현************ -> x좌표, y좌표 따로따로 생각!! + for문
-함수 정의** -> 함수 틀 잡기 고민! 
    -> 매개변수를 3개나 잡아야 된다는 점을 못 잡았다!!!
    -> x좌표, y좌표를 따로 생각해야 되고, n변 종이니까 매개변수 3개
    -> for문을 x좌표, y좌표 따로 생각해서 0,3,6 시작 인덱스로 for문 2번 돌리는 거 생각!!
      
      -> 즉, 쫄지말고 (0,0,3) (0,3,3) (0,6,3)
                  (3,0,3) (3,3,3) (3,6,3)
                  (6,0,3) (6,0,3) (6,0,3) 으로 좌표 관찰 마인드!
    solve(x,y,n); n크기의 종이에서 x좌표부터 시작하고 y좌표부터 시작하는 종이의 숫자가 모두 같을 때 동안 9등분
-base condition 
-재귀식

+ 변수 3개를 저장하는 1개의 배열로 축약!
*/
#include <iostream>

using namespace std;
int paper[2200][2200];
int cnt[3]; // -1로 채워진 종이의 개수, 0으로 채워진 종이의 개수, 1로 채워진 종이의 개수

bool check(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
        if (paper[x][y] != paper[i][j])
            return (false);
        return (true);
}

void solve(int x, int y, int z)
{
    if (check(x,y,z))
    {
        cnt[paper[x][y]+1] += 1;
        return ;
    }

    int n = z / 3;
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        solve(x + i*n, y + j*n, n);

}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
    }
    solve(0,0,n);
    
    for (int i = 0; i < 3; i++)
        cout << cnt[i] << '\n';
}