// queue hint : FIFO !! 
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; // n : 4

    queue<int> que;
    for (int i = 1; i <= n; i++) // 1, 2, 3, 4
    {
        que.push(i); // 1 2 3 4 으로 push됨
    }
    while (que.size() != 1)
    {
        que.pop(); // 2 3 4 //  4 2 // 4
        int ret = que.front(); // 2 // 4 // 4
        que.pop(); // 3 4 // 2 // 
        que.push(ret); // 3 4 2 // 2 4 // 4
    }
    cout << que.front() << '\n';
}