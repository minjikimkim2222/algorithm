// 원형 큐 base 이해
/*
1 2 3 4 5 6 7 <- 초기 상황
2 3 4 5 6 7 1 <- 1을 뒤에 넣기, push(1)
3 4 5 6 7 1 2 <- 2를 뒤에 넣기, push(2)
4 5 6 7 1 2 <- 세 번째 사람, 3 pop
5 6 7 1 2 4 <- 4를 뒤에 넣기, push(4)
6 7 1 2 4 5 <- 5를 뒤에 넣기, push(5)
7 1 2 4 5 <- 세 번째 사람, 6 pop
1 2 4 5 7 <- 7을 뒤에 넣기, push(7)
2 4 5 7 1 <- 1을 뒤에 넣기, push(1)
4 5 7 1 <- 세 번째 사람, 2 pop
5 7 1 4 <- push(4)
7 1 4 5 <- push (5)
1 4 5 <- 세 번째 사람, 7 pop
4 5 1
5 1 4
1 4 <- 5 pop
4 1, push(1)
1 4, push(4)
4 <- 1 pop
1개 남음 <- 그냥 pop 할 것 (4 pop)

그리고 진짜로 복잡하게 생각하지 말고, 단순하게 알고리즘을 생각하자!
3의 배수에 막 매몰되지 말고 그냥 1,2,3하고, 1,2,3하고, 1,2,3.. 으로 반복된다고 생각하면 쉬움.
필요없는 변수를 늘리지 말 것!
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n,k;
    cin >> n >> k; // 7,3

    queue<int> Q;

    for (int i = 1; i <= n; i++)
        Q.push(i);
    
    cout << "<";
    while (Q.size() > 1){
    // 큐 사이즈가 2 이상일 때
        for (int i = 1; i < k; i++){
            int temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
        cout << Q.front() << ", ";
        Q.pop();

    }

    // 큐의 사이즈가 1일 때, 큐에 1개 남았을 경우
    cout << Q.front() << ">";
    

}