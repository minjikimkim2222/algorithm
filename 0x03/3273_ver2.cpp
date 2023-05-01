// 3273에서는 binary search를 통해 key가 있는지 찾아다니며 count ++1을 했는데,
// 이 문제는 존재 여부로 판단을 해 코드가 깔끔해졌다. ->>> bool형 자주 사용하기

#include <iostream>
#include <algorithm>

using namespace std;

int a[100001] = {};
bool occur[200001]; //각 자연수의 존재 여부를 저장하는 배열. x - arr[i]가 100001보다 큰 경우 예외처리하기 싫어서

int n,x;

int main(void)
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    for (int i = 0; i < n; i++){
        // x - a[i]가 존재하는지 확인
        if (x-a[i] > 0 && occur[x-a[i]]) ans++;
        occur[a[i]] = true;
    }
    cout << ans;
    
}