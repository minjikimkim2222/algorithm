// 제목 : BFS 응용 4 -> 1차원에서의 BFS

/*
0. 특이하게도 BFS
    1) 기존에 봤던 BFS는 '이차원'배열에서 '상하좌우'의 전파 모습
    2) 해당 예제는, '1차원' 배열에서 이동하는 모습!

1. **BFS catch 2번째 ver : 이동 중, "최단"거리,최단시간 등등.***** 
    -> **dist[]배열을 채우면서, 최단 거리를 구할 수 있게 하는 BFS!
        처음 방문하고, 이전 것의 거리 + 1

2. 구현
    1) if문, 유효범위 --> input에서 0~100,000이라 0~100,000은 아님.
        (일단 받아들이기) 100,000 바깥으로 넘은 다음 다시 돌아올수도. 
        그러나, 애초에 100,000을 넘으면 -1을 계속 해야 하므로, 애초에 안 나가는 게 이득이긴 함.(강의안 참고)
`   2) bfs를 2번 돌릴 필요 없음!! 필요한 수빈이 거리배열만 있으면 됨!!

    3) 범위 기반 for문 새로운 형태 -> 초기화 리스트에 있는 각 요소를 변수 nxt에 대입!!
        for(int nxt : {cur-1, cur+1, 2*cur}){
            
        }

    4) while문 조건 -> !q1.empty() 대신 ,dist[k] == -1
        !q1.empty()는 dist[k]를 찾지 못한 채로 프로그램을 종료할 수 있지만,
        dist[k] == -1를 조건으로 계속 찾으면 결국 dist[k] 가 -1이 아닌, 즉 최단거리를 찾은 순간 바로 리턴이 되므로!

-> 해당 문제는 1차원 배열을 채워가며, BFS 최단거리 특징이 있음을 캐치하는 것!
*/

#include <iostream>
#include <queue>

int dist1[100002]; // 수빈이 거리
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k; // 수빈 위치, 동생 위치
    for (int i = 0; i < 100002; i++)
        dist1[i] = -1; // 수빈 거리 배열 전부 -1로 초기화
     // 방문 x = dist배열 -1
    
    queue<int> q1; // 수빈

    q1.push(n); // 수빈 시작 위치 방문
    dist1[n] = 0;

    while (dist1[k] == -1){ 
        auto cur = q1.front();
        q1.pop();
        for (int x : {cur - 1, cur + 1, 2*cur}){
            if (x < 0 || x > 100000) continue;
            if (dist1[x] >= 0) continue;
            dist1[x] = dist1[cur] + 1;
            q1.push(x);
        }
    }
    cout << dist1[k] << '\n';
}