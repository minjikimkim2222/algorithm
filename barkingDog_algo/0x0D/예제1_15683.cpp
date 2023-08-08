/*
어려워서 해설을 참고했다. -> 솔직히 너무 어려움,,
1. 문제 이슈 
    - 방향 관련 -> BFS 코드 구조에서, 상하좌우 -> "각 CCTV 방향 분리 생각!"

    - 상,하,좌,우 -> "행렬에서의 좌표"와 "좌표평면 상에서의 좌표"는 다르다!
        행렬에서의 좌표 관점에서 dx[4], dy[4]를 생각해줄 것!!
        -> if문 여러 개를 두어, cctv번호별로 탐색할 방향 마련해둠

    - 90도 회전? -> 회전에 관여하는 지역변수 dir 설정
        방향(우,상,좌,하)을 "고정"할 dir 매개변수를 선언해주고, dir에 따라 감시 영역을 탐색한다.
        dir 1이 증가하면, dx,dy 인덱스가 각각 1씩 증가했으므로, 90도 회전한다!

2. 참고 링크
    https://seokjin2.tistory.com/108 <- first
    https://0m1n.tistory.com/115 <- second

3. 백트래킹
    -> dfs함수는 백트래킹을 활용해 "모든 경우의 수"를 탐색!
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8][8];
vector<pair<int, int>> cctv;
int ans = 987654321;

int dx[4] = {0, -1, 0, 1}; // 우, 상, 좌, 하
int dy[4] = {1, 0, -1, 0};

void check(int x, int y, int dir){
    dir %= 4;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if(arr[nx][ny] == 6) return;
        if(arr[nx][ny] != 0) continue;
        arr[nx][ny] = -1;
    }
}

void dfs(int idx){
    if(idx == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(!arr[i][j]) cnt++;

        ans = min(ans, cnt);
        return;
    }
    
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int tmp[9][9];

    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                tmp[i][j] = arr[i][j];

        if(arr[x][y] == 1)
            check(x, y, dir);
        else if(arr[x][y] == 2){
            check(x, y, dir);
            check(x, y, dir+2);
        }
        else if (arr[x][y] == 3){
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (arr[x][y] == 4){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2); 
        }
        else if (arr[x][y] == 5){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx+1);
        // case 종료이므로 초기화
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                arr[i][j] = tmp[i][j];
    }    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6)
                cctv.push_back({i, j});
        }
    }

    dfs(0);
    cout << ans << '\n';

    return 0;
}