/*
1. 1이 "상하좌우"로 연결된 것 "방문/순회/탐색" 그림 => BFS 유추!

2. 의문점 : 
    그림 크기는 pop개수로 하면 될 거 같은데,
    그림 개수는? -> <<<<<BFS의 시작점>>>>>?

3. 처음 출발점을 (0,0)을 했고 그 후, (0,1), (0,2), (0,3)으로 각각 출발점이 되기
위한 조건을 관찰해볼 것 -> 2중 for문, "board[i][j]가 있는데 왜 pair 고민을 하지?"

4. 구현 : 그냥 board[502][502]로 크게 두고 초기화는 n, m까지만 하도록

5. c++ min, max함수 (std::min, std::max 함수임, <algorithm>헤더)
min(1,2) // 1 return
min(2,2) // 2 return
min('b','d') // 'b' return
min(345.678, 123.456) // 123.456 return

max(1,2) // 2 return
max(2,2) // 2 return
max('b', 'd') // 'd' return
max(345.678, 123.456) // 345.678 return

-> 즉, 특히 BFS 시작점 관련 조건을 생각해보고, BFS 기본탐색에 대한 내용이었음.

*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int board[502][502];
bool visit[502][502];
int n, m; // 행,열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int board[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    // input complete

    int count = 0; // 그림의 개수
    int max_area = 0; // 그림의 넓이 최대값

    // 시작점 찾기 -> (i,j)로 찾음!
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (visit[i][j] || board[i][j] == 0) continue; // 방문 이미 했거나, 방문 불가능한 곳(0)이면 pass!

            queue<pair<int,int>> Q;
            visit[i][j] = 1;
            Q.push({i,j}); // 시작지점 방문하고 큐에 넣음
            count++; // 그림 시작점 개수 = 그림 개수

            int area = 0; // 현재 그림 넓이 매번 시작점 찾은 후 초기화
            while (!Q.empty()){
                pair<int,int> cur = Q.front();
                Q.pop();
                area++;

                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visit[nx][ny] || board[nx][ny] == 0) continue;
                    visit[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            } 
            // 큐가 다 비었다 -> 1개의 그림 넓이를 다 쟀다.
            max_area = max(area, max_area);
        }
    } 
    cout << count << '\n' << max_area;
}
