/*
0. 제일 큰 관점으로, "문제에 맞게" 귀납적 사고 생각
    -> 근데 여기서는 "문제에 맞게", 방문여부보다는 "방문순서"에 초점을 두어 재귀적으로 살펴봄
    -> 예시를 통해 얻은 결론,
        n = k로 얻은 결과를 가지고, n = k+1의 결과를 구할 때 써먹을 수 있다!

1. 구현 ************* 함수 틀 잡기 연습!! ******
    1) 함수의 정의
    int func(int n, int r, int c)
    // 2^n 2^n 배열에서 (r,c)를 방문하는 "순서"를 반환하는 함수
    2) base condition
    // n=1이면 별도의 처리를 해줘야 되므로,
    // n = 0일 때, return (0);
    3) 재귀식 -> 앞선 예시에서 봤듯, (r,c)가 어느 사각형에 있는지에 따라 처리 다름
    + 제일 큰 관점으로 생각, (2^n)(2^n) 배열에서 r행 c열 방문순서!
    half는 한 변 길이의 절반, 2^n-1이다.
    (r,c)가 1번 사각형일 때, return func(n-1,r,c);
    (r,c)가 2번 사각형일 때, return (half*half + func(n-1, r, c-half);
    (r,c)가 3번 사각형일 때, return (2*half*half + func(n-1, r-half, c));
    (r,c)가 4번 사각형일 때, return (3*half*half + fucn(n-1, r-half, c-half));

-> 즉, 이전 단계와의 관계를 "문제에 맞게" 귀납적인 사고를 할 것

3. 추가. 비트 연산자
    1) 1 << n ; n비트만큼 왼쪽으로 이동 [2^n]형태로 기억 
    (1 << 2) -> 4; 2^2
    (1 << 3) -> 8; 2^3
    2) >> ;주로 왼쪽이동연산자를 위주로 씀. 얘는 반대라는 것만 기억
    (8 >> 2) -> 2

*/

#include <iostream>

using namespace std;

int func(int n, int r, int c)
{
    if (n == 0)
        return (0);
    else
    {
        int half = 1 << (n-1); // 2^k-1
        if (r < half && c < half) return (func(n-1,r,c));
        if (r < half && c >= half) return (half*half + func(n-1, r, c-half));
        if (r >= half && c < half)  return (2*half*half + func(n-1, r-half, c));
        if (r >= half && c >= half) return (3*half*half + func(n-1, r-half, c-half));
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,r,c;
    cin >> n >> r >> c;
    int result = func(n,r,c);
    cout << result << '\n';
}
