// dfs는 bfs 기본 코드에서 큐를 스택으로 바꾼 것밖에 차이가 없다!
#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int board[502][502];
int vis[502][502];

int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    stack<pair<int, int>> S; // 수정된 부분
    vis[0][0] = 1;           // 시작점 방문
    s.push({0, 0});

    while (!S.empty())
    {
        pair<int, int> cur = S.top();
        S.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위 out?
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1) // 이미 방문했거나, 방문 불가능한 지역이면
                continue;
            via[nx][ny] = 1; // 모든 예외를 if문으로 제거한 다음 방문
            S.push({nx, ny});
        }
    }
}