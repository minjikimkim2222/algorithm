// 불2 : 4179랑 뭐가 다를까? -> while문 도는 점이 다른 듯요.
/*
1. 내 생각  -> 결론적으로 틀린 생각.
시작점이 2개인 BFS인데, 서로 영향을 주는
    1. 상근 -> 불의 위치에 따라 이동 불가, 이동 가능 결정됨.
    2. 불[추가] -> 불이 상근이가 있던 위치로 전파된 후, 상준이가 "동시에" 다른 칸으로 이동 가능.
    -> 따라서 상근이와 불의 BFS를 '시간순으로' '동시에' 진행하자.
        <불, 상근이 시작 위치 각각 큐에 넣기>
        0. 불 전파 먼저
        1. 전파된 불의 위치가 상근이의 위치면, 그와 동시에 상근이는 이동한다! 
        상근이는 불이 붙거나 붙을 예정이면 이동 불가. 상근이 전파.
        2. 또또 불의 전파

2. 구현 삽질 -> 근데 개 틀림 [1번 대로 했더니..]
    일단 칭찬할 점 : 물레벨 아니게끔, 내가 디버깅해보는 과정도 필수. 그렇게 시간을 쏟다가 3~4시간 지나면 체크

    1. 생각할 구간 : 상근이와 달리 불은 시작지점이 여러 개임(*을 여러 개 입력 받기 가능)
        -> 내 생각이 틀림. 불 먼저 하고 상근이 해야 함. *이 여러 개면 각각의 시작점을 큐에 담은 뒤, 불 먼저 각 시작점을 토대로 BFS를 돈 결과를 바탕으로,
        상근이도 BFS를 돌아야 한다고 생각합니다. 
    2. 고치고 나니, 백준 테케 3,4[둘다 impossible 나오는 거 안됨] -> 이유 생각 ㄱㄱ
        -> if문 수정. 제어문 조건을 고침. distS[cur.first][cur.second] + 1 >= distF[nx][ny] 일 때 continue로 고침
    3. 제대로 출력되는 걸 고치고 나니 "런타임에러"
    3-1) 입출력문제
        1) 공백없이 입력받는 거라 string 추측 -> test_2.cpp를 해보고 나니 애매해. 그냥 char c로 중간에 입력받는 2)로 바꿔서 내가 할 수 있게 하자@!!!!!!!
            근데 test_2.cpp로 해보다 보니 개헷갈리고 모르겠음.
            그냥 아는 거 쓰자 -> 2번!!
        2) char c를 선언해서 매번 c를 입력받자! -> 일단 받아들이기
        3) 출력을 개행으로
    3-2) logic 문제
        1) 매번 큐를 empty로 비워주기 + !flag 조건 추가
        -> *** flag가 true로 변경[원하는 조건을 만족해 탈출했음에도] while문을 빠져나가지 않으면, dist가 정답이 아닌 다른 거리값으로 변경될 수 있어서 !flag조건을 씀
        -> 근데 중간에 탈출하면 큐에 원소가 들어있을 수 있으므로, while문 처음에 큐를 비워줘야 함!!
        2) if문에서 distS >= distF 에서 distF != -1 조건꺄지 같이 챙겨줘야 함
            distF = -1인 거리는, distS + 1 [-1 + 1] >= distF[-1]인 조건을 만족시켜서, continue하게 되니까 예외 조건을 써줘야 한다.

*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int board[1002][1002];
int distS[1002][1002]; // 상근이 거리
int distF[1002][1002]; // 불 거리
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int,int>> QS; // 상근이 큐
queue<pair<int,int>> QF; // 불 큐

int w,h;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        bool flag = false; ////// flag 초기화 위치 수정!!
        cin >> w >> h;
        while (!QS.empty()) QS.pop();
        while (!QF.empty()) QF.pop();
        // dist[h][w]
        for (int i = 0; i < h; i++){
            fill(distS[i], distS[i] + w, -1);
            fill(distF[i], distF[i] + w, -1); // dist 둘 다 -1로 초기화[0이면 시작위치임]
        }
        for (int i = 0; i < h; i++){ // arr[h][w]
            for (int j = 0; j < w; j++){
                char c;
                cin >> c; 
                if (c == '@'){
                    QS.push({i,j});
                    distS[i][j] = 0; //  시작위치 방문 표시
                }
                if (c == '*'){
                    QF.push({i,j});
                    distF[i][j] = 0; // 시작위치 방문 위치
                }
                board[i][j] = c;
            }
        }
        // dist 각각 초기화 마침

        // 불 BFS
        while (!QF.empty())
        {
            auto cur = QF.front();
            QF.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == '#' || distF[nx][ny] >= 0) continue;
                distF[nx][ny] = distF[cur.first][cur.second] + 1;
                QF.push({nx,ny});
            }
        }

        while (!QS.empty() && !flag)
        {
            auto cur = QS.front();
            QS.pop();

            // cout << "QS, pop, (x,y) : " << cur.first << ", " << cur.second << ' ';
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) // 탈출!
                {
                    cout << distS[cur.first][cur.second] + 1 << '\n';
                    flag = true;
                    break; // while문이 아닌 for문을 빠져나감
                }
                if (board[nx][ny] == '#' || distS[nx][ny] >= 0 ) continue;
                if (distF[nx][ny] != -1 && distS[cur.first][cur.second] + 1 >= distF[nx][ny]) continue;
                distS[nx][ny] = distS[cur.first][cur.second] + 1;
                QS.push({nx,ny});
            }
        }
    
        if (!flag) // while문으로 탈출 후에도, 올바른 cout이 출력되면 flag = 1로 설정할 것 
            cout << "IMPOSSIBLE\n"; 
    }
    return (0);
}