#include <iostream>
#include <vector> // vector STL 

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1(3,5); // {5,5,5} = 3개의 원소를 5로 초기화
    cout << v1.size() << '\n'; // 3
    v1.push_back(7); // {5,5,5,7}

    vector<int> v2(2); // {0,0} => 2개의 원소, default 0으로 초기화
    v2.insert(v2.begin() + 1, 3); // insert(1,3) -> index 1에 3 추가
                                  // 한칸씩 밀려가며, 0, 3, 0
    vector<int> v3 = {1,2,3,4};
    v3.erase(v3.begin() + 2); // 1,2,4

    vector<int> v4; // {}
    v4 = v3; //vector도 복사가능, {1,2,4}
    cout << v4[0] << v4[1] << v4[2] << '\n';
    v4.pop_back(); // {1,2}
    v4.clear(); //{}

}