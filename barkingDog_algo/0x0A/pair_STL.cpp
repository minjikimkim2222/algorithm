/*
값의 쌍을 저장할 수 있는 pair
주로 좌표를 생성할 때, 이 pair을 씀
    -> 해당 목차에서는 BFS 탐색할 때, 큐에 좌표를 넣어야 하는데 이때 pair를 씀
*/

#include <iostream>
#include <utility> // pair 정의 헤더

using namespace std;

int main(void){
    pair<int,int> t1 = make_pair(10,13);
    pair<int,int> t2 = {4,6};

    cout << t1.first << '\n';
    cout << t2.second << '\n';

    // 쌍 중에 첫번째 원소를 first로 접근, 두 번째 원소를 second로 접근

    if (t2 < t1) cout << "t2 < t1\n";  // t2 < t1
    // pair은 알아서 앞쪽부터 대소관계 비교한 뒤, 뒤 까지 검사함
    
}