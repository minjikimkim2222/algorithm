// 제목 : 응용3 - "시작점이 '두 종류' 일때"
/*
0. BFS 힌트
    1) "수평 또는 수직으로 이동" "각 지점에서 네 방향으로 확산"
        -> "상하좌우"로 확산되는 모양!

1. 시작점이 두 개일 경우, 해결책!
    -> 각각의 BFS를 돌린다. 이때, 하나의 BFS를 전부 돌린 뒤, 그 값을 기준으로 나머지 BFS를 돌려 확인한다.

2. 구현
1) distF 배열 전역변수라 처음에 전부 0.
    따라서 방문여부를 구분짓기 위해, 처음에 -1로 모두 초기화.
    방문하면 0 이상의 양수
    즉, distF가 -1이면 아직 방문 안 함. 0이상이면, 이미 방문함!
2) 언제 impossible이고 언제 성공인지
    **BFS 특징, 큐에는 거리순으로 들어감!!
    지훈이 BFS if문 조건 겁나 수정
3) if문 블럭 제대로 안해서 틀림

3. 추가 생각

이 문제는 지훈이는 불의 전파에 영향을 받고, 불은 지훈이의 위치에 영향을 받지 않기에, 불을 먼저 BFS한 후 고정시킨 다음 풀 수 있었음
-> 즉, 만일 두 종류의 BFS를 돌 때, 어느 하나가 독립적이지 않고 서로에게 영향을 준다면 지금 문제방식으로는 해결불가!
-> 그럴 때는 "시간 순으로 A와 B를 동시 진행" [문제를 더 풀어보며 깨달을 수 있는 지점]

*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int r,c;
string board[1002];
int distF[1002][1002]; // 불 dist
int distJ[1002][1002]; // 지훈 dist
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++){
        fill(distF[i], distF[i] + c, -1); // -1로 초기화
        fill(distJ[i], distJ[i] + c, -1);
    }

    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;

    for (int i = 0; i < r; i++)
        cin >> board[i];

    for (int i = 0; i < r ; i++){
        for (int j = 0; j < c; j++){
            if (board[i][j] == 'F'){
                Q1.push({i,j}); // 'F'는 시작지점
                distF[i][j] = 0;
            }
            if (board[i][j] == 'J'){
                Q2.push({i,j});
                distJ[i][j] = 0;
            }
        }
    }
    while (!Q1.empty()){ // 불 BFS
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (board[nx][ny] == '#' || distF[nx][ny] != -1) continue;
            Q1.push({nx,ny});
            distF[nx][ny] = distF[cur.first][cur.second] + 1;
        }
    }

    while (!Q2.empty()){
        auto cur = Q2.front();
        Q2.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {/// *** 범위를 벗어났다 -> 탈출을 의미!!!!! , 큐는 거리순으로 쌓임, 최초의 탈출시간
                cout << distJ[cur.first][cur.second] + 1;
                return (0);
            }
            if (distJ[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (distF[nx][ny] != -1 && distF[nx][ny] <= distJ[cur.first][cur.second] + 1) continue; // 불의 전파 시간 조건에 추가!!
            Q2.push({nx,ny});
            distJ[nx][ny] = distJ[cur.first][cur.second] + 1;
        }

    }
    cout << "IMPOSSIBLE"; // 여기에 도달 -> 탈출실패!

}


