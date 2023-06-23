#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502] =
    {
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};                  // 1이 방문가능한 지역, 0은 안됨
bool vis[502][502]; // 해당 좌표 방문 여부 저장
int row = 7, col = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    queue<pair<int, int>> Q;
    vis[0][0] = 1; // 이 예제는 bfs의 시작점을 (0,0)으로 고정해서 이와 연결된 지점을 전부 탐색할 것
    Q.push({0, 0});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = 1; // 방문 표시 까먹지 말것!!!
            Q.push({nx, ny});
        }
    }
}