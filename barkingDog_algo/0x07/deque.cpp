#include <iostream>

using namespace std;

const int MAX = 1000005;
int data[2*MAX + 1];
int front_var = MAX, rear_var = MAX;

void push_front(int x)
{
    data[front_var - 1] = x;
    front_var--;
}

void push_back(int x)
{
    data[rear_var] = x;
    rear_var++;
}

void pop_front()
{
    front_var++;
}

void pop_back()
{
    rear_var--;
}

int front()
{
    return (data[front_var]);
}

int back()
{
    return (data[rear_var - 1]);
}

int main(void)
{
    push_back(30); // 30
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 30

    push_front(25); // 25 30
    push_back(12); // 25 30 12
    cout << back() << '\n'; // 12

    push_back(62); // 25 30 12 62
    pop_front(); // 30 12 62
    cout << front() << '\n'; // 30

    pop_front(); // 12 62
    cout << back() << '\n'; // 62

}