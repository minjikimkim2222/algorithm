// 제목 : BFS 응용 2 - 시작점이 "여러 개"일 때
/*
0.  BFS 느낌 잡은 방법
    1) 토마토가 익는 상황 자체 -> "상하좌우"로 퍼지는 느낌
    **2) 일차원 배열, 최단거리 [응용1] -> 토마토가 다 익기까지의 "최소일수"**
        => "모든 익지 않은" 토마토들에 대해 "가장 가깝게" "상하좌우" 위치한 토마토까지의 거리

1. 시작점이 여러 개인 BFS 해결법
    1) 여러 시작점에 대해 각각의 BFS 돌리기 -> 시간복잡도 O(n*m) -> 개오바 ㅇㅇ
    2) 처음부터 시작점은 전부 큐에 넣고 빼면 되잖아! *** 

2. 헷갈리는 지점
    시작점이 익지 않은(0) 토마토임? 익은(1) 토마토임? -> 익은 토마토. 왜냐, 익은 토마토를 큐에서 꺼낸 다음 그 근처 0인 애들을 방문할 거니깐.

3. 구현 틀린 지점
    1. 전역변수 int나 int배열은 따로 초기화 안 하면, 0으로 초기화됨.
        즉, 코드에 따르면, 익은 토마토가 들어있거나 토마토가 없다면 dist값이 0!
    2. if문 제어조건 -> dist[nx][ny] >= 0에서 양수도 넣은 이유 : 방문하게 되어 dist값이 0이상이 될 수도!
    3. 마지막에 ans값에 따라 다른 출력값
        1) dist배열을 잘 활용할 것!
            처음에 3가지 경우로 잘 나누기
            dist = -1 -> 익지 않은 토마토
            dist = 0 -> 익거나 토마토가 없는 경우
            dist >= 0 -> 시작지점, 이미 방문한 지점 

4. 제출 -> 런타임 에러 -> 리턴값을 0으로 안해서..
    리턴값을 0으로 해야 정상종료고,
    리턴값 -1은 예외처리 시 비정상종료임.

*/

#include <iostream>
#include <queue> // BFS
#include <algorithm>

int m,n;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;

    queue<pair<int,int>> Q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({i,j}); // 시작지점 큐에 넣기
            if (board[i][j] == 0)
                dist[i][j] = -1; // 익지 않은 토마토 거리배열은 -1로 초기화
                // 전역변수로 인해, 익은 토마토나 토마토가 없는 dist배열값은 0
        }
    }

    while (!Q.empty()){
    
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0) continue; // 양수도 빼먹으면 안됨.(이미 방문[양수]했거나, 방문불가능지역[토마토가 없거나, 익은 토마토])
            dist[nx][ny] = dist[cur.first][cur.second] + 1; // 방문했다!
            Q.push({nx,ny});
        }
    }

    int ans = 0; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if (dist[i][j] == -1){
                cout << "-1\n";
                return (0);
            }
            ans = max(ans, dist[i][j]);
        }
    }

    if (ans == 0){
        cout << "0\n";
        return (0); // dist가 전부 0이다! 처음부터 모두 익은 토마토뿐
    }
    cout << ans << '\n';


}