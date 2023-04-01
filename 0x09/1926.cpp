#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502]; // 1이 파란칸, 0이 빨간 칸
bool vis[502][502];  // 방문 여부 check
int row, col;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> board[i][j];
    int mx = 0;  // 그림의 최대값
    int num = 0; // 그림의 개수

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (vis[i][j] || board[i][j] == 0)
                continue;
            num++; // (i,j는 시작점이라 그림 개수 증가)
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1; // (i, j) 를 방문했다!
            int area = 0;  // 그림의 넓이는 bfs 시작점(i,j)에서 연결된 지점, 즉 pop연산할 때마다 더해진다
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++; // 큐에 들어있는 원소를 뺄 때마다 area 더해짐
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx > row || ny < 0 || ny >= col)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] == 0)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            // (i,j)을 시작점으로 하는 bfs가 종료됨.
            mx = max(mx, area); // stl에 정의된 max함수. 번외로 min함수도 알아둘 것, 두 인자의 값을 비교해서 큰값/작은 값을 리턴하는 함수
        }
    }
    cout << num << '\n'
         << mx;
}