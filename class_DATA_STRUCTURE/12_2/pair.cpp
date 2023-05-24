#include <iostream>
#include <utility> // 해당 헤더에 pair 존재

using namespace std;

int main(void)
{
    pair<int, double> myPair(10, 3.14);

    cout << "First Value : "<< myPair.first << '\n';
    cout << "Second Value : " << myPair.second << '\n';

    myPair.first = 20;
    myPair.second = 2.71;

    cout << "Modified First Value : " << myPair.first << '\n';
    cout << "Modified Second Value : " << myPair.second << '\n';

    return (0);
}