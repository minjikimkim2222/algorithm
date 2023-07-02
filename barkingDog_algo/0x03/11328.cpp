/*
1. 구현 삽질
    1) flag 설정하고, 최종적으로 break가 안되서 end 변수 추가 
        -> 근데 로컬에서는 맞았는데, 문제에서는 실패?!
        -> 이유 : 문제 파악 실패
        문제에서는 s1의 모든 문자가 s2에 있는지를 확인하고 싶은데, 
        나는 s1의 문자가 s2에 존재하는지 여부만 체크해서, 일부 테스트 케이스에 실패하는 것임.
        따라서 2번 시도로!
    2) s1은 알파벳의 개수를 더해주고, s2는 알파벳의 개수를 매번 빼줘서, 알파벳 배열에 0이 아닌 무언가가 있다면
    두 문자열은 같지 않다는 것!
    [아이디어 참고]  
    3) s1.size랑 s2.size 따로 따로 초기화
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int alpabet[26];
    bool flag;

    while (t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
  
        fill(alpabet, alpabet+26, 0); // 매번 0으로 초기화
        flag = true;
        
        for (auto c : s1) alpabet[c-'a']++;
        for (auto c : s2) alpabet[c-'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (alpabet[i] != 0){
                flag = false;
                break;
            }
        }

        if (flag == 1)
            cout << "Possible\n";
        else
            cout << "Impossible\n";

    }
    return (0);

}