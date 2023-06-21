#include <stack>
#include <iostream>

using namespace std;

int main(void)
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30); // 10 20 30

    cout << s.size() << '\n'; // 3

    if (s.empty()) cout << "s is empty\n";
    else cout << "s is not empty\n"; // s is not empty

    s.pop();
    cout << s.top() << '\n'; // 20

    s.pop();
    cout << s.top() << '\n'; // 10

    s.pop();
    cout << s.top() << '\n'; // runtime error
    // stack이 비었는데, 맨 위 원소 출력하라니까 쓰레기값, 이상한 값이 출력됨
}