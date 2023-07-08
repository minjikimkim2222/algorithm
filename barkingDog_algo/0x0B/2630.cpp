/*
1. 재귀 -> 1780 백준 문제랑 비슷

2. 함수 틀 잡기
    1) 재귀식 부분, for문으로 어떻게 호출할 지 헷갈려서 1780 참고함
        - 지금 주어진 미지수가 n이라는 것을 활용하자!

3. 구현
    1. check함수, main모두 문제 없어 보이는데, 재귀식 부분 함수에 문제가 있어 보임. 출력이 이상하게 됨.
    -> else문에 n = n / 2; 로 했는데 디버깅 결과 n이 계속 나눠지니까 이상해짐.
    -> 그래서 새로운 변수 하나를 설정해야 됨.

    -> 근데 변수 계속 늘리니까 이상해서 그냥 다 지우고 다시! 답안 참고
    -> 재귀 부분을 제대로 이해하지 못했음을 깨닮.
    -> 작은 예제부터 확인해보면,
    n = 4일 때, (0,0,4) -> (0,0,2), (0,2,2), (2,0,2), (2,2,2)를 호출하고,
               (0,4,4) -> (0,4,2), (0,6,2), (2,4,4), (2,6,4)를 호출함을 알면,
               재귀식 작성 가능!!
*/

#include <iostream>

using namespace std;

int arr[130][130];
int n;
int ans[2]; // 순서대로 [0] : 하얀색 색종이, [1] : 파란색 색종이
int origin_n;

bool check(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (arr[x][y] != arr[i][j])
                return (false);
            return (true);
}

void solve(int x, int y, int n)
{
    if (check(x,y,n) == true)
    {
        ans[arr[x][y]]++;
        return ;
    }
    else
    {
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                solve(x + i*n/2, y + j*n/2, n/2);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    origin_n = n;
    solve(0,0,n);
    // output
    cout << ans[0] << '\n';
    cout << ans[1] << '\n';
}
