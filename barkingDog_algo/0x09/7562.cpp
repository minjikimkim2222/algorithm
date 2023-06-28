/*
1. BFS 특징 -> 원하는 목적지까지 "최소" 몇번 이동? dist배열 관찰
    + 퍼지는 곳이 "상하좌우" 느낌으로, "한 지점"에서 그 지점에서 갈 수 있는 곳 다 간 다음, 그 다음 지점으로 이동하는 느낌인지!
    + BFS와 최소 연관 -> 이미 갔던 곳을 또 방문하지 않는다. 최소 이동횟수, 그 다음 이동을 +1로 세준다

2. 구현 삽질 
    1) 여태 하던 대로, dx[8]이랑 dy[8]을 이동할 곳으로 좌표 이동을 시킴.
    2) dist[nx][ny] <- nx, ny가 행렬의 index이기에 음수가 되면 안 되는 걸 예외사항으로 이미 빼줌! <- 이 의미 다시금 상기
    3) 변수 중복 선언!!으로 에러가 떴음
    4) if문 수정** [cout을 if문 도착했다가 아닌 while문 전체 다 돌고 난 다음에 출력하게 하는 이유]
        bfs는 큐에 좌표를 추가한 뒤, 해당 좌표에서 인접한 좌표를 다 돌고 갱신된 최단 거리를 출력한다.
        그런데 만일, if문에서 처음에 도착지에 도착한 경우 출력하게 되면, 큐에 남아있는 다른 좌표들은 탐색하지 않은 채로 남아있게 되어, 결과적으로 올바르게 갱신된 최단거리를 출력할 수 없게 한다.
        따라서 while문으로 큐가 다 빈 다음에서야, 최종 최단거리를 출력할 수 있도록 한다.
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[302][302];
int dist[302][302];

int dx[8] = {1, 2, -1, -2, -2, -1, 1, 2};
int dy[8] = {2, 1, 2, 1, -1, -2, -2, -1};
queue<pair<int,int>> Q;

void bfs(int, int);
int l;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    cin >> count;
    while (count--){
        cin >> l; // 체스판 크기 (l*l)
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
                dist[i][j] = -1; // 방문 안 한 거리를 전부 -1로 초기화
        int x,y;
        cin >> x >> y; // 시작 좌표
        Q.push({x,y});
        dist[x][y] = 0; // 시작 좌표 방문 표시
        int destX,destY;
        cin >> destX >> destY; // 도착좌표 (destX,destY)

        bfs(destX,destY);

    }
}

void bfs(int destX,int destY) // 도착좌표 전달
{
    while (!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 8; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (dist[nx][ny] >= 0) continue; // 이미 방문한 곳이면 지나치기
            // if (nx == destX && ny == destY) { // 목적지에 도착했다!
            //     cout << dist[cur.first][cur.second] + 1;
            //     return ;
            // }
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});

        }
    }
    cout << dist[destX][destY] << '\n';
}