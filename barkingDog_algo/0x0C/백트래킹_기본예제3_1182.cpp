/*
1. 문제 이해
    - 공집합은 빼고, 2^n-1개의 모든 부분집합에 대해, 합이 S인 경우기 몇가지가 있는가?
    - 부분수열 -> 부분집합을 구하는 것과 비슷하게 생각해보자!
2. 관점
    - 함수 내에서 i번째 수를 더할지 말지 정하고, i+1번재 수를 정하러 한 단계 더 들어간다는 관점에서
    고민해볼 것! -> 백트래킹 기본 구조, i번째 수를 더할지 말지..!

3. 구현
    - 함수의 인자로 현재의 합까지 가져가게 함.
    - 문제에서 양수인 부분수열만 센다 = 공집합 제외
        s가 0이 아닐 때에는 상관없고, s가 0일때는 cnt에서 1을 빼줘야 한다!

4. 이건 어려워서, 구조 관찰 공부!

*/

#include <iostream>

using namespace std;

int n, s;
int arr[22];
int cnt;

void backtracking(int cur, int tot_sum)
{
    if (cur == n)
    {
        if (tot_sum == s) cnt++;
        return ;
    }

    else
    {
        backtracking(cur+1, tot_sum);
        backtracking(cur+1, tot_sum + arr[cur]);
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    backtracking(0,0);
    if (s == 0) cnt--;
    cout << cnt;


}