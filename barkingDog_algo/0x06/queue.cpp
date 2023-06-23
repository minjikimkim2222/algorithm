// 원형 큐가 아닌 선형 큐를 간단히 배열로 구현
#include <iostream>

using namespace std;

const int MAX = 1000005;
int data[MAX];
int front = 0, rear = 0; // front, rear 초기화는 둘 다 0

void push(int x)
{
    data[rear] = x;
    rear++;
}

void pop()
{
    front++;
}

int front_fun()
{
    return (data[front]);
}

int back() // 주의! index가 rear이 아닌 rear-1 임을!
{
    return (data[rear - 1]);
}

int main(void)
{
    push(10); push(20); push(30);
    cout << front_fun() << '\n'; // 10
    cout << back() << '\n'; // 30

    pop(); pop(); // 30 **FIFO**
    push(15); push(25); // 30 15 25
    cout << front_fun() << '\n'; // 30
    cout << back() << '\n'; // 25
}