#include <iostream>

using namespace std;

int n,m;
int arr[10]; // 출력할 수열을 저장할 배열
bool isused[10]; // 해당 숫자가 쓰였는지 저장할 배열

void func(int k)
{
    if (k == m) // m개를 모두 택했다면,
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= n; i++) // 1부터 n까지의 수에 대해
    {
        if (!isused[i]) // 아직 숫자 i가 사용되지 않았다면 
        {
            arr[k] = i; // k번째 수를 i로 정함
            isused[i] = true; // 숫자 i를 사용했다고 표시
            func(k+1); // 다음 수를 정하기 위해 한 단계 더 들어감
            isused[i] = false;
            // ** k번째 수를 i로 정한(arr[k] = i)로 한 모든 경우를 다 사용했으니,
            // i를 이제 다른 순서에서도 사용가능하도록 false라 할 것

            // arr[k] = i로 둔 상태에서 func(k+1)에 들어갔다가 모든 과정을 끝냈다는 얘기이니, isused[i] = false로 되돌려, i가 사용되지 않고 있음을 명시

            // 아직 for문 안에 있음을 잊지 말자!
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
