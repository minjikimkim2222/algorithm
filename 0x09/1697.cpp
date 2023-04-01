#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dist[100002];
int n, k;

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < 100002; i++)
        dist[i] = -1; // 방문 안 함 -1
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    // 초기화 + 시작값 큐에 넣었으니 이제 dfs 시작
    while (dist[k] == -1) // 조건식이 바뀜. 큐가 빌 때까지가 아니라, 언니가 동생을 찾을 때까지! -1이 아니면 찾았다는 얘기니까!
    {
        int cur = Q.front();
        Q.pop();
        for (int next : {cur - 1, cur + 1, 2 * cur})
        {
            if (next < 0 || next > 100002)
                continue;
            if (dist[next] >= 0)
                continue;
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    cout << dist[k];
}