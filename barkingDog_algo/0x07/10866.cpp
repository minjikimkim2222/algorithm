#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    deque<int> DQ;

    while (n--)
    {
        string s;
        cin >> s;

        if (s == "push_back")
        {
            int data;
            cin >> data;
            DQ.push_back(data);
        }
        else if (s == "push_front")
        {
            int data;
            cin >> data;
            DQ.push_front(data);
        }
        else if (s == "front")
        {
            if (DQ.empty()) cout << "-1\n";
            else cout << DQ.front() << '\n';
        }
        else if (s == "back")
        {
            if (DQ.empty()) cout << "-1\n";
            else cout << DQ.back() << '\n';
        }
        else if (s == "size")
        {
            cout << DQ.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << DQ.empty() << '\n';
        }
        else if (s == "pop_front")
        {
            if (DQ.empty()) cout << "-1\n";
            else{
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if (s == "pop_back")
        {
            if (DQ.empty()) cout << "-1\n";
            else{
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
    }
}