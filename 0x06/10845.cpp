#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> que;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            que.push(num);
        }
        else if (s == "front")
        {
            if (que.empty()) cout << -1 << '\n';
            else{
                cout << que.front() << '\n';
            }
        }
        else if (s == "back"){
            if (que.empty()) cout << -1 << '\n';
            else cout << que.back() << '\n';
        }
        else if (s == "size"){
            cout << que.size() << '\n';
        }
        else if (s == "empty"){
            if (que.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (s == "pop")
        {
            if (que.empty()) cout << -1 << '\n';
            else{
                cout << que.front() << '\n';
                que.pop();
            }
        }
    }

}