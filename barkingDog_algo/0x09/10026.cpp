/*
1. BFS [상하좌우 이동] -> dist 배열 고민해볼것
    + BFS : 시작점 고민 [board배열에 2가지 값이 아닌 3가지 값]

2. 구현
    전체적인 아이디어는 맞다. 틀린 이유?
        1) BFS if문 조건 단순화!!!
            3가지 값 board에 매몰된 게 아니라, 처음 방문하면 count하면 됨 [visit배열 입장!!]
            그리고 적록색약 = 빨,초 구분 불가 = R을 G와 똑같이 취급하기!
        2) 반복되면 -> 함수로 빼!

    -> 매몰되지 말고 근본에 몰입해서 visit 배열 과정을 생각해봐!!

*/

#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

string board[102];
bool visit[102][102]; // 처음에 전부 방문 안 한 값 : 0
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
queue<pair<int,int>> Q;

void bfs(int i, int j);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    // input complete

    int count1 = 0; // 적록색약 아닌 사람
    int count2 = 0; // 적록색약인 인간
    // 시작점을 찾아, 큐에 넣는 작업 **
    for (int i = 0; i < n; i++){ //(열,행) -> 열 고정 후, 행 순서대로 찾기 = 밑에서부터 쭉 돌고, 오른쪽으로 탐색
        for (int j = 0; j < n; j++){
            if (visit[i][j] == 0){
                count1++;
                bfs(i,j);
            }
        }
    }
    cout << count1 << ' ';

    for (int i = 0 ; i < n; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j] == 'G') //  모든 G를 R로 바꾸기(적록색약은 G나 R이나 똑같음)
                board[i][j] = 'R';
            visit[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){ //(열,행) -> 열 고정 후, 행 순서대로 찾기 = 밑에서부터 쭉 돌고, 오른쪽으로 탐색
        for (int j = 0; j < n; j++){
            if (visit[i][j] == 0){
                count2++;
                bfs(i,j);
            }
        }
    }
    cout << count2;

}

void bfs(int i, int j){
    Q.push({i,j}); 
    visit[i][j] = 1;

    while (!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visit[nx][ny] == 1 || board[nx][ny] != board[i][j]) continue;
            Q.push({nx,ny});
            visit[nx][ny] = 1;
        }
    }
    return ;
}