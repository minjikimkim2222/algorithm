#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];

int m, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    cin >> m >> n;
    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({i, j});
            if (board[i][j] == 0)
                dist[i][j] = -1; // 익지 않은 토마토, 즉 아직 방문 안함
        }
    }

    // dfs를 돌리자 시작점을 전부 큐에 넣었으니
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    // 반환값. 토마토가 전부 익는데 걸리는 일수 계산해야 함.
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return (0);
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}