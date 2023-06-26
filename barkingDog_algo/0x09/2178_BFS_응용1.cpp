// 제목 : BFS 응용1 "다차원 배열에서의 거리 측정"

/*
0. 탐색을 해당 칸의 "상하좌우"로 탐색하는 느낌 -> BFS 유추!

1. BFS -> "상하좌우"칸들을 방문 + 시작점과의 거리 계산 가능!
    1) visit배열 대신 dist 거리 배열
    ***2) 현재 칸으로 추가되는 "인접한" 칸은 거리가 현재 칸보다 1만큼 떨어져있음***
    3) 의문이었던 부분 -> 해결
        문제 예시에서 (0,4) 뒤에 (1,4) or (0,5), 즉 둘 중 어느 걸 먼저 방문하느냐에 따라 최단 거리가 달라질 거라고 생각했음.
            그러나, 해당 관찰칸의 상하좌우의 칸들은 전부 동일하게 해당 칸의 +1 처리되니까
                즉, (1,4)나 (0,5) 모두 10 + 1 = 11 로 거리가 계산됨. 따라서 둘 중 어느걸 먼저 방문해도 최단거리는 잘 구할 수 있음.

2. 구현
- 문자가 띄어서 입력받지 (1 1 1 1) 않고, 붙어서 (1111)로 입력 -> string을 쓰자!
- <algorithm header> fill함수

3. 안된다면 3가지 점검
    1) 시작지점에서 방문했다는 표시를 했는가?
    2) 큐에 push하고 방문했다는 표시를 했는가?
    3) ***유효한 범위 설정 제한 + 방문 이미 한 부분/방문불가 부분** if문 조건을 맞게 했는가?

4. 최종적으로는 string으로 받았으니 0이 아닌 '0'으로 해야 함을 수정함

*/

#include <iostream>
#include <queue>

using namespace std;

string board[102]; // 입력이 2~100이랬음
int dist[102][102]; // visit 대신 dist 배열
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i]; // input complete -> string 사용! board[0][2]로 접근도 가능!

    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
        // 거리 배열 -1로 초기화 == 거리배열값이 -1이면 한번도 방문 안 한 것임
    queue<pair<int,int>> Q;
    dist[0][0] = 0; // 시작지점 방문(거리 0으로 두기)
    Q.push({0,0});

    while (!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] =='0') continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});

        }
    }
    cout << dist[n-1][m-1] + 1 << '\n';

}