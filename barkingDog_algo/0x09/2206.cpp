/*
1. BFS 감 -> 상하좌우, 최단경로
2. 구현 -> 쫄지 마!!
    1) 일단 새로운 점 : 한 개의 벽을 부수어서 최단 경로를 갈 수 있다면, 벽 한 개까지만 부술 수 있다.

    2) BFS는 항상 최단 경로를 보장한다?
    -> "각 가중치가 모두 동일한 경우(ex 1), 최단 거리를 보장한다."
    -> BFS는 방문하지 않은 상하좌우의 인접한 노드를 모두 방문하기에, 각 이동 거리가 1씩 증가한다.
       만일, 가중치가 다른 경우, BFS로 찾은 경로가 최단 경로가 아닐 수 있다.

    3) 벽을 깰 당위성?
    -> 그러나, 해당 문제에서는 BFS로 이동한 거리가 최단 경로로 보장되기에,
       현재 갈 곳이 없는데, 선택한 곳 주위에 0이 있다면 벽을 깰 당위성이 성립된다.
       
    4) 입력을 "공백없이" 받음 -> string 사용
        -> 5427 still 의문 솔찍히..
        -> string 사용 시, board[i][j]는 int가 아닌 char형임을 인지할 것!

    5) 반복문 범위 별로 사용가능한 변수 제한.. hard
    6) if문 조건 수정
        -> board[i][j] == 1이 아니고, board[i][j] == '1'임!

    // 이렇게 스스로 풀어본 결과, 로컬에서 답이 나오는데, 채점 결과 segfault가 뜸..
    1) string을 int로 바꾸고 [board 타입을]
    2) for문 안에 for문을 dir로 똑같이 써서, 명확하지 않아 안쪽 for문 변수를 dir2로 바꿈
    -> 이 결과 segfault는 안 뜨는데, 채점 결과 23%에서 틀림

3. 질문 전, 최종 시도
    -> 반례 질문게시판에서 검색 (5,5)
    00000
11110
00000
01111
00010
>답은 9인데, 17로 이상하게 나온 것을 확인!
    -> 이 반례 확인 결과, 내가 벽을 뚫는 기준이 문제에서 요구하는 것과 다름을 확인
        나 : 벽 뚫기 = 최초의 1로 전부 막혀있을 때
        문제 요구 : 벽 뚫기 = 그 벽을 뚫음으로써, 최단 거리가 더 짧아짐에 영향을 끼칠 때!
    -> 갈아엎고 문제 정답코드 관찰함.. 흑흑

*/
// #include <iostream>
// #include <queue>
// #include <utility>
// #include <algorithm>

// using namespace std;

// int board[1002][1002];
// int dist[1002][1002];

// int dx[4] = {0,-1,0,1};
// int dy[4] = {1,0,-1,0};
// int N,M;
// queue<pair<int,int>> Q;

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
 
//     cin >> N >> M;

//     for (int i = 0; i < N; i++){
//         string row;
//         cin >> row;
//         for (int j = 0; j < M; j++){
//             board[i][j] = row[j] - '0'; // char to int
//         }
//     } 
    
//     for (int i = 0; i < N; i++)
//         fill(dist[i], dist[i] + M, -1); // -1로 전부 초기화
//     // input and initialize

//     Q.push({0,0}); // 시작지점 넣기
//     dist[0][0] = 1;

//     int limit = 1; // 벽 뚫기 기회 1번 제한 변수
//     while (!Q.empty())
//     {
//         auto cur = Q.front(); 
//         Q.pop();
        
//         for (int dir = 0; dir < 4; dir++){
//             int nx = cur.first + dx[dir];
//             int ny = cur.second + dy[dir];

//             if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//             if (dist[nx][ny] > 0 || board[nx][ny] == 1) continue; // dist 배열은 시작지점부터 1 이상이니까, 0 포함 안 시킴
            
//             Q.push({nx,ny});
//             dist[nx][ny] = dist[cur.first][cur.second] + 1;

//         }
//             if (Q.empty() && limit == 1)
//             {

// ;                for (int dir = 0; dir < 4; dir++)
//                 {
//                 int nx = cur.first + dx[dir];
//                 int ny = cur.second + dy[dir];

//                     if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//                     if (dist[nx][ny] > 0) continue;
//                     if (board[nx][ny] == 1) // 벽이 있는 곳
//                     {
//                         for (int dir2 = 0; dir2 < 4; dir2++) // 주위에 0이 있는 (nx,ny)의 벽을 뚫고 싶다
//                         {
//                             int x2 = nx + dx[dir2];
//                             int y2 = ny + dy[dir2];

//                             if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) continue;
//                             if (dist[x2][y2] > 0 || board[x2][y2] == 1) continue;
//                             if (board[x2][y2] == 0){ // 주위(x2,y2)에 0이 있는 (nx,ny)
//                                 board[nx][ny] = 0; // 벽 뚫기
//                                 Q.push({nx,ny});
//                                 dist[nx][ny] = dist[cur.first][cur.second] + 1;
//                                 limit = 0;
//                                 break;
//                             }
//                         }
//                         limit = 0; // 이제 사용 금지 [벽 뚫기 기회제한 1]
//                     }
//                     }
//                 }
//         }

//         if (dist[N-1][M-1] == -1)
//             cout << "-1\n";
//         else {
//         cout << dist[N-1][M-1] << '\n';
//         }
// }

/*
1차 시도 패기.
2차 시도 -> 애초에 문제에 맞게 처음부터 짜자!!
    1차 시도 실패 이유 : BFS가 최단거리 보장해주건 맞는데, 해당 반례를 확인해보니 내 논리 잘못
    여기서 챙길 구현 아이디어 -> 새롭게 추가할 변수 등장 시, 큐와 dist배열을 1개씩 늘려 tuple과 3차원 배열을 사용한다!

1. 구현 -> 2)번 아이디어 챙겨감
    1) cin을 char형 board로 하면, 공백없이 입력이 되는 것을 확인[앞선 5427 의문점 확인]

    2) 최단거리에 도움 되는 벽 뚫기 체크해야 함-> dist 배열에 추가함. dist[x][y][broken]
        - 벽을 부쉈을 때와 벽을 안 부쉈을 때의 2가지 경우의 거리 배열 풀이
            -> 벽을 부쉈을 때를 최단거리로 해서 가다가 또 다른 벽을 만나는 경우, 해당 경로는 막힌 경로가 된다.
            이때 좀 돌아오더라도, 벽을 부수지 않고 왔던 경로가 있다면, 다시 경로를 탐색할 수 있기에
            두 가지의 dist배열을 나눠서 생각하는 것이 핵심!
    
    3) tuple을 각각의 원소 접근 tie로 해당 변수 초기화
    tie(x,y,broken) = q.front();

*/

#include <iostream>
#include <utility>
#include <queue>
#include <tuple> // tuple header

using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

char board[1000][1000];
int dist[1000][1000][2]; // dist
/*
dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)인 벽을 부숨
*/
int n,m;


bool OOB(int x, int y) // 유효한 범위 체크 함수!
{
    return (x < 0 || x >= n || y < 0 || y >= m); 
}

int bfs()
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            dist[i][j][0] = dist[i][j][1] = -1;
    }
    
    // 시작지점 2개 다 1로 거리 초기화
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int,int,int>> Q; // (x,y,broken)
    Q.push({0,0,0});

    while(!Q.empty())
    {
        int x,y,broken;
        tie(x,y,broken) = Q.front(); // broken의 큐의 front부분을 뽑을 때마다 초기화됨
        if (x == n-1 && y == m-1) return (dist[x][y][broken]); // 최종 목적지 도착 시 리턴해서 main에서 출력하도록
        Q.pop();

        int nextdist = dist[x][y][broken] + 1; // 미리 변수를 저장해둠[for문에서 쓰임]
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (OOB(nx,ny)) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = nextdist;
                Q.push({nx,ny,broken});
            }
            // (nx,ny)를 부수는 경우, broken이 0일 때만으로 제한하기 위해 if문에 broken 추가
            if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) // dist 배열이 -1로 처음 벽 부술 때
            {
                dist[nx][ny][1] = nextdist;
                Q.push({nx,ny,1});
            }
        }
    }
    return (-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    cout << bfs();
    return (0);
}
