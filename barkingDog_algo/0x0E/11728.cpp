/*
for문 안에 4개의 조건을 전부 if로 하면, idx가 증가한 상태에서 다른 조건에 걸릴 수도 있기에
else if로 해준다!

stable sort 관련 : 둘의 크기가 같을 때 앞쪽의 원소, 즉 a[aidx]가 c에 들어가야 한다!
*/

#include <iostream>

using namespace std;
int n,m;
int a[1000005], b[1000005], c[2000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

// input
    cin >> n >> m; // 배열 A 크기, 배열 B 크기
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

// sort   
   int aidx = 0, bidx = 0;

    for (int i = 0; i < n+m; i++)
    {
        if (bidx == m) // b배열 다 채움. c배열에 남은 a배열 전부 넣기
        {
            c[i] = a[aidx++];
        }
        else if (aidx == n) // a배열에 넣을 거 다넣음. b배열에 남은 거 전부 c배열에 넣기
        {
            c[i] = b[bidx++];
        }
        else if (a[aidx] > b[bidx]) c[i] = b[bidx++];
        else if (a[aidx] <= b[bidx]) c[i] = a[aidx++];
       
    }

   for (int i = 0; i < n+m; i++) cout << c[i] << ' ';
   cout << '\n'; 
}
