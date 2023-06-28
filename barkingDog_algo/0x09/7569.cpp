// 7576 토마토 문제랑 비슷해보임 2차원 --> 3차원 ; 
/*

1. BFS 힌트지점 -> 좀 쫄았지만 3차원이 되며 추가되는 축들, 좌표들이 차이점 같군.
    1) x,y,z
    2) 상하좌우 + 앞/뒤 => 추가된 차원의 BFS
    3) 익는 과정도 BFS 형태고, 거리배열을 채워 최소거리/일수를 구하는 형식도 BFS 형식

2. 구현 중 삽질
1) 2차원 배열, 3차원 배열 indexing + test.cpp 파일
    헷갈렸던 2차원 배열 + 행렬 matrix 정리[이게 맞다] : 링크 https://woodforest.tistory.com/115 참고 int arr[행][열]
    3차원 배열 indexing 알아두기 : int arr[면][행][열] ; 링크 : https://blog.naver.com/pisibook/221509766219 참고.

     [그림으로 아는대로 받아들여라]
     [열0][열1][열2][열3][열4]
[행0] 0    -1   0    0   0
[행1] -1   -1   0   1    1
[행2] 0    0    0   1    1
-> m : 5 -> 열
-> n : 3 -> 행 
-> h : 높이
arr[n][m] !!
+  높이 추가
arr[h][n][m]


2) 2개 이상의 데이터로 묶을 때는 pair이 아닌 turple, tie함수
-> + 2개 이상의 데이터를 묶을 때는 pair이 아닌 tuple
    tie함수를 이용해 tuple의 원소를 각각의 변수로 분해해 초기화가능

3) 마지막에 if문 조건 수정.
*/
#include <iostream>
#include <queue> // BFS
#include <utility>
#include <algorithm>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1}; // 1개의 축이 1/-1을 가지고 나머지들은 0을 가진 형태로 초기화


int m,n,h; 
int board[102][102][102];
int dist[102][102][102];

queue<tuple<int,int,int>> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h; // arr[h][n][m] 으로 초기화
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> board[i][j][k];
            if (board[i][j][k] == 1)
                Q.push({i,j,k}); // 시작지점은 큐에 넣기 (방문표시를 0으로 안 해도 이미 다 초기화가 0으로 되어있음)
            if (board[i][j][k] == 0)
                dist[i][j][k] = -1;
        } // 전역변수에 의해 안 익은 토마토도 0으로 초기화되었는데, 구분짓기 위해 안 익었다면 -1을 거리배열에 넣기!
    }/*
dist 배열 BFS 처리 이후,
-> dist배열에 -1이 존재 = 토마토가 모두 익지 못함 [뒤에서 초기화를 해줌]
    왜냐, 초기화를 안 익은 토마토면 dist값을 -1로 그 외(익거나 토마토가 없다면 0으로 해놓앗으니)
-> dist배열의 최대값이 0이면 = 처음부터 모든 토마토가 익은 상태
    왜냐, 0인 토마토를 하나도 발견 못했으니까 dist배열이 전역변수라 처음부터 0으로 초기화된 상태를 유지할테니.
*/
    }

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (dist[nx][ny][nz] >= 0 || board[nx][ny][nz] == 1) continue;
                dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                Q.push({nx,ny,nz});
        }
    }
    
    int ans = 0;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                if (dist[i][j][k] == -1){
                    cout << "-1\n";
                    return (0); // 안 익은 토마토 존재 = 모두 다 못 익음
                }
                ans = max(ans,dist[i][j][k]);
            }
        }
    }

    if (ans == 0){
        cout << "0\n"; // 시작할 때부터 모든 토마토 익어있음
        return (0);
    }

    cout << ans << '\n';
}