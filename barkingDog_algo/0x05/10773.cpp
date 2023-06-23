#include <iostream>
#include <stack> //LIFO -> 가장 최근 게 먼저 지워짐! 이 특징이 중요!

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    while (n--)
    {
        int input;
        cin >> input;
        if (input > 0)
        {
            st.push(input);
        }
        else if (input == 0)
        {
            st.pop();
        }
    }
    int sum = 0;
    while (!st.empty()){
        sum = sum + st.top();
        st.pop();
    }
    cout << sum;
}