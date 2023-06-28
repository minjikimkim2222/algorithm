#include <iostream>
#include <stack> // DFS
#include <utility>

using namespace std;

int board[502][502] = 
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 방문 가능 지역, 0이 방문 불가능 지역

bool visit[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n = 7, m = 10; // n : 행, m : 열
 int main(void)
 {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> S;

    S.push({0,0}); // 시작지점 넣기
    visit[0][0] = 1; // 시작지점 방문 표시

    while (!S.empty()){
        auto cur = S.top();
        S.pop();

        cout << '(' << cur.first << ", " << cur.second << ") -> ";
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 바깥
            if (visit[nx][ny] == 1 || board[nx][ny] == 0) continue; // 이미 방문했거나 방문 불가능 지역은 지나치기
            visit[nx][ny] = 1;
            S.push({nx,ny});
        }
    }
 }