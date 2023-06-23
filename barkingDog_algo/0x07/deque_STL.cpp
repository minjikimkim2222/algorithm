#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;

    DQ.push_front(10); // 10
    DQ.push_back(50);  // 10 50
    DQ.push_front(24); // 24 10 50

    for (auto temp : DQ)
        cout << temp << ' '; // 24 10 50
    cout << DQ.size() << '\n'; // 3

    if (!DQ.empty()) cout << "Deque is not empty\n";
    else cout << "Deque is empty";

    DQ.pop_front(); // 10 50
    DQ.pop_back(); // 10
    cout << DQ.back() << '\n'; // 10

    DQ.push_back(72); // 10 72
    cout << DQ.front() << '\n'; // 10

    DQ.push_back(12); // 10 72 12

    /*특이하게도 스택과 큐와 달리 STL deque는 insert, erase함수도 있고 인덱스로 원소 접근 가능!*/
    DQ[2] = 17; // 10 72 17
    DQ.insert(DQ.begin() + 1, 33); // 10 33 72 17 
    // vector STL에서도 봤듯이, insert랑 erase에는 iterator 반복자가 들어가야 함
    DQ.insert(DQ.end(), 60); // 10 33 72 17 60

    for (auto temp : DQ)
        cout << temp << ' '; // 10 33 72 17 60
    cout << '\n';

    DQ.erase(DQ.begin() + 3); // 10 33 72 60
    cout << DQ[3] << '\n'; // 60

    DQ.clear(); // DQ의 모든 원소 제거!
}