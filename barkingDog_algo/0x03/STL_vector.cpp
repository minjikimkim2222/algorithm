#include <iostream>
#include <vector> // vector STL 

using namespace std;

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    case1. STL_vector 기본 예제
    */
    // vector<int> v1(3,5); // {5,5,5} = 3개의 원소를 5로 초기화
    // cout << v1.size() << '\n'; // 3
    // v1.push_back(7); // {5,5,5,7}

    // vector<int> v2(2); // {0,0} => 2개의 원소, default 0으로 초기화
    // v2.insert(v2.begin() + 1, 3); // insert(1,3) -> index 1에 3 추가
    //                               // 한칸씩 밀려가며, 0, 3, 0
    // vector<int> v3 = {1,2,3,4};
    // v3.erase(v3.begin() + 2); // 1,2,4

    // vector<int> v4; // {}
    // v4 = v3; //vector도 복사가능, {1,2,4}
    // cout << v4[0] << v4[1] << v4[2] << '\n';
    // v4.pop_back(); // {1,2}
    // v4.clear(); //{}

    /*
    case2. STL_vector 순회
    */
   vector<int> v1(6,1); // {1,1,1,1,1,1}
   v1.push_back(7); // {1,1,1,1,1,1,7}
   v1.insert(v1.begin() + 2, 5); // {1,1,5,1,1,1,1,7}
   
   cout << "v1.size() : " << v1.size() << '\n';

   // 1. 범위 기반 루프(c++ 11 이상부터 제공) -> 이미 정리해둠. study에
   for (auto temp : v1)
    cout << temp << ' ';

    cout << "\nsecond\n\n";
   // 2. not bad
   for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << ' ';

    cout << "\n\njust curious\n";

    vector<int> v2(3);
    v2.push_back(3); // 0,0,0,3

    for (auto temp : v2)
        cout << temp << ' '; // 0,0,0,3
    cout << '\n';
    
    v2.insert(v2.end(), 4); // 0,0,0,3,4

    v2.insert(v2.end() -1, 5); // 0,0,0,3,5,4
    for (int temp : v2)
        cout << temp << ' ';


}