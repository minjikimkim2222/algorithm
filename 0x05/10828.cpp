#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> st; // stack 선언

    while (n--) // n번 반복
    {
        string s; // cpp -> string 자료형 있음!!!!
        cin >> s;
        if (s == "push")
        {
            int n;
            cin >> n;
            st.push(n);
        } 
        else if (s == "top")
        {
            if (!st.empty())
            {
                cout << st.top() << '\n';
            }
            else cout << -1 << '\n';
        }
        else if (s == "pop")
        {
            if (!st.empty())
            {
                cout << st.top() << '\n';
                st.pop();
            }
            else cout << -1 << '\n';
        }
        else if (s == "size")
        {
            cout << st.size() << '\n';
        }
        else if (s == "empty")
        {
            if (st.empty())
                cout << 1 << '\n';
            else cout << 0 << '\n';
        }
       
    }
}