#include <iostream>

using namespace std;

int arr[8]; // 출력할 수열을 저장하는 배열

int n, m;

bool check_condition(int depth, int value)
{
    for (int i = 0; i < depth; i++)
    {
        if (arr[i] == value)
            return (false);
    }
    return (true);
}

void dfs(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (check_condition(depth, i) == true)
            {
                arr[depth] = i;
                dfs(depth + 1);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    dfs(0);
}
