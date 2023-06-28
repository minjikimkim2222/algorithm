/*
1. BFS -> "상하좌우 관찰"
2. 유형 4가지
    1) 2차원 배열, 최단 거리 -> 인접한 곳은 +1
    2) 2차원 배열, 여러 시작점 -> 여러 시작점이 관찰되면 큐에 push해놓기
    3) 2차원 배열, 시작점 2종류 (단, 서로 영향을 주지 않는 조건) -> 각각의 BFS 돌기 (다른 것의 영향을 받지 않는 하나 먼저 돌고, 나머지 돌기)
    4) 1차원 배열, 최단 거리[최단 시간], -> dist 배열을 관찰하며 깨닫기
-> 여러 시작점을 처음에 다 찾아서 넣기 아닌 거 같다. 매번 BFS 시작점을 찾아서 count하는 것이지, 모든 1인 board의 개수를 처음부터 전부 큐에 넣는 게 아니다.

3. 구현 -> 전체적인 로직에는 문제가 없는데 입력받는 것, 초기화를 다시 할 것, 행과 열을 거꾸로 쓰는 것을 바로잡는데 오래걸림
 1) 입력값 어떻게 입력받을까.
 2) 각 테스트케이스에 대한 값을 따로 출력! -> 함수 쪼개기도 추천[코드가 너무 기니깐]
 3) 안되는 지점 -> check 3가지
    1. 시작지점 방문표시?
    2. 방문 = 큐에 push?
    3. ****if문 제어조건****  -> 틀린 조건 1개 고침
 4) m과 n을 자꾸 거꾸로 쓴다. + x,y로 입력받은 거를 board[y][x]로 해야 하는 것!!!
   -> 7269에서 그림으로 헷갈리지 않게 바로잡음!
 5) !!!! 틀린 이유, 다시 반복문을 돌리기에 visit과 board배열 초기화를 다시 해줘야 함!!

 + 코드가 길어지니, bfs(i,j) 함수를 따로 만들기!
*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

int n,m; // 행, 열
bool visit[52][52]; // 방문여부, 전역변수니까 0이 저장됨
int board[52][52]; // 전역변수 초기화 0 -> 배추 없음, 1 -> 배추 있음[후에 입력받음]
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    cin >> count;
    while (count--){
        cin >> n >> m; // 행,열
        int k,x,y; 
        cin >> k; // 배추 위치 개수 ( 17 )
        for (int i = 0; i < k; i++){
            cin >> x >> y;
            board[y][x] = 1; // 배추 있다!
        }
    // input complete
    int ans = 0;
    queue<pair<int,int>> Q;
    for (int i = 0; i < m; i++){ // 시작점 찾기
        for (int j = 0; j < n; j++)
            if (board[i][j] == 1 && visit[i][j] == 0){ // 방문하지 않았다는 조건도 추가했어야!
                Q.push({i,j});
                visit[i][j] = 1; // 방문 여부 표시!
                ans++; // 시작점 발견 시 count
                while (!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= m|| ny < 0 || ny >= n) continue;
                        if (visit[nx][ny] == 1 || board[nx][ny] == 0) continue; // 조건 틀림!!!!!  (borad[][] == 0!!)
                        Q.push({nx,ny});
                        visit[nx][ny] = 1;
                    }
                }
            }
    }
    cout << ans << '\n';

    for (int i = 0; i < m; i++){
        fill(board[i], board[i] + n, 0);
        fill(visit[i], visit[i] + n, false);
    }

    }
}