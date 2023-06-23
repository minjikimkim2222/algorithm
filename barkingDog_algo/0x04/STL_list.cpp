#include <iostream>
#include <list> //list_STL 헤더

using namespace std;

int main(void)
{
    list<int> L = {1,2};

    list<int>::iterator t = L.begin(); //literator는 주소를 가리키는 일종의 포인터 역할, 여기서는 1을 가리킴
    L.push_front(10); // 10,1,2
    cout << *t << '\n'; // 1을 출력할 것

    L.push_back(5); // 10,1,2,5
    
    L.insert(t, 6); // t가 가리키는 곳의 바로 앞에 삽입, 즉, 10,6,1,2,5
    t++; // t가 2를 가리킴

    t = L.erase(t); // t가 현재 가리키는 2를 제거 + 그 다음 원소인 5의 위치 반환
    //현재 t가 가리키는 값은 5
    cout << *t << '\n'; // 5

    // 여기서부터는 순회부분!
    for(auto temp : L)
        cout << temp << ' ';
    cout << '\n';
    
    for(list<int>::iterator ptr = L.begin(); ptr != L.end() ;ptr++)
        cout << *ptr << ' ';

}