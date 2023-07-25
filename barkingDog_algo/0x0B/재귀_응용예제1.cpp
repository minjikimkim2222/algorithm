/*
1. 재귀 예제 01]ab mod m -> 귀납적 사고 일깨우기
구현 삽질
1) 입력과 리턴값이 엄청 커져 long long 으로 수정
2) 시간복잡도
    문제 시간 제한 : 2초 [1초에 3~5억번의 연산, 즉 2초에 10억번 안에]
    근데 첫 구현 -> O(n) -> n = 21억[정수 최대값], 21억번의 재귀호출이 일어나 실패!
    그래서 시간복잡도를 낮추기 위해, b가 짝수일때와 홀수 일 때를 나누어 생각해보자!
*/

// 1) 1차 시도 [int overflow를 고려한 수식, ab mod m] + 반복문

// long long func1(long long a, long long b, long long m)
// {
//     long long val = 1;
//     while (b--) val = val * a % m;
//     return (val);
// }

/*
1-반복문)의 시간복잡도는 while문을 보아 O(b).
근데 해당 문제는 b가 최대 21억이라, O(21)억. 시간 제한은 0.5초
1초당 3억~5억번의 연산. 근데 21억의 연산? 어림도 없다.
*/

#include <iostream>

using namespace std;

long long func(long long a, long long b, long long m)
{
    if (b == 1)
    {
        return (a%m);
         // 제일 밑, 제일 base condition에서 1승을 계산해줘야, 
         // 귀납적 사고로 k승 -> 2k, 2k+1승도 해결가능
    }
    long long val = func(a, b/2, m);
     // a^6 % 5과 a^7 % 5을 예시로 생각! 
     // a^3[k] -> a^6 [2k], a^7[2k+1승]
    val = val * val % m;
    if (b%2 == 0) return (val);
    else if (b%2 == 1) // 홀수승은 b/2로, 한번 a를 못 곱해서 다 곱한 뒤 나눌 수 있게
    {
        return (val * a % m);
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;

    cin >> a >> b >> c;
    cout << func(a,b,c) << '\n'; 
}

/*
2번 시도. "**제일 큰 틀에서**" "귀납적인 사고로" 생각해라

if문 -> base condition 
    여기에는 자명한 사실을 씀. 재귀 종료 조건

재귀식 -> 임의의 지수 승을 "귀납적으로" 계산 가능
    1승을 계산됨을 보이면,
    k승 계산한다면 -> 2k, 2k+1도 계산가능
그외 -> k승 계산한다면, 2k[짝수승]과 2k+1[홀수승]도 계산 가능!

이 코드의 시간복잡도 -> b가 절반씩 줄어들어 o(logb) -> 성공! 
*/