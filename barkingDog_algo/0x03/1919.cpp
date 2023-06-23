// 1. 제발 string 쓰는 걸 아까워말라!

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int idx1 = 0, res = 0;

    while (s1[idx1])
    {
        int idx2 = 0;
        while (s2[idx2])
        {
            if (s1[idx1] == s2[idx2] && s2[idx2] != '1'){
                 // 같은 것이 존재
                s2[idx2] = '1';
                s1[idx1] = '1'; 
            }
            idx2++;
        }
        idx1++;
    }

    int i = 0;
    while (s1[i])
        if (s1[i++] != '1') res++;    
    i = 0;
    while (s2[i])
        if (s2[i++] != '1') res++;
    cout << res;
}