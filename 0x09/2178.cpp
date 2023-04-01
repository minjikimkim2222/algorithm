#include <queue>
#include <iostream>
using namespace std;
#define X first
#define Y second

string board[102]; // map, 방문가능한 곳 1, 아닌 곳 0
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int row, col;
int dist[102][102]; // 초기화 -1, 방문할 때마다 +1

int main(void)
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        cin >> board[i];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            dist[i][j] = -1;
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') // 이미 방문한 곳이나, 방문할 수 없는 곳이라면 지나친다!
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[row - 1][col - 1] + 1;
}