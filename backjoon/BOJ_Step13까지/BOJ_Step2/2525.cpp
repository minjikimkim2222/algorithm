#include <iostream>

using namespace std;

int main(void)
{
    int h,m;
    int howManyMinutes;
    int totalMinutes;
    // 시와 분을 하나의 분으로 "통합", 추가된 분을 더한 뒤,
    // 최종 분을 다시 시와 분으로 변환
    cin >> h >> m >> howManyMinutes; // 14, 30, 20

    // 14 30, 20
    totalMinutes = h * 60 + m + howManyMinutes;

    h = (totalMinutes / 60) % 24; // 24시 이상이 될 경우, 0부터 시작 // 나머지 연산의 새로운 정의 
    m = totalMinutes % 60;
    cout << h << ' ' << m;
}