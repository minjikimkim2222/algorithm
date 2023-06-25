#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1 : 파란칸 (방문가능한 곳), 0 : 빨간칸(방문 안할 곳)

 bool visit[502][502]; // 해당 칸의 방문 여부를 저장

 int n = 7, m = 10; // 각각 행과 열

 int dx[4] = {1,0,-1,0};
 int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향

 int main(void)
 {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q; // 좌표를 위한 좌표
    
    visit[0][0] = 1; // 시작지점 (0,0)을 방문했다!
    Q.push({0,0});

    while (!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++){ // 상하좌우
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 유효한 범위가 아님(범위 밖인 경우 넘어감)
            if (visit[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나, 파란 칸이 아닌 경우
            visit[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
 }