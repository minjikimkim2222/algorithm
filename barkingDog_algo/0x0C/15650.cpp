// 15649랑 다르게, 오름차순 배열임을 기억해야 한다!
// 시작지점을 잡고, 오름차순 배열이니까 int i는 항상 시작지점보다 큰 애들이 와야 한다!
#include <iostream>

using namespace std;

int ans[10];
bool isused[10];
int n, m;

void func(int k) // ans[k]번째에 수열 채워넣는 함수
{
    if (k == m) // m개를 다 골랐다!
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return ;
    }

    int start = 1; // k = 0일 때
    if (k > 0) start = ans[k-1] + 1; // k > 0일 때 시작지점!
    for (int i = start; i <= n; i++)
    {
        if (!isused[i])
        {
            ans[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}