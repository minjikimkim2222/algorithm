/*
문자 그대로 받아들여서 그대로 해주면, 복잡해지는 경우가 있다. 
문제를 쪼개서 생각하자!!!! + 6,9일때와 같이 특수한 경우는 여러 예제를 보고 하나의 수식 결정!

핵심 : 각 0~9까지의 숫자의 개수를 세서 배열에 저장한다. 단, 6과 9는 동일하게 생각한다.
그리고 난 뒤, 각 배열의 원소의 최대개수를 구한다!

*/

// #include <iostream>

// using namespace std;
// int main(void)
// {
//     int n;
//     cin >> n;
//     int arr[10] = {0};

//     while (n)
//     {
//         arr[n%10]++;
//         n = n / 10;
//     }
//     //6과 9는 서로 사용가능하기에 평균값으로 보정.
//     arr[6] = (arr[6] + arr[9] + 1) / 2;
    
//     int max = 0;
//     for (int i = 0; i < 9; i++) //arr[6]에 arr[9]까지 보정됨.
//     {
//         if (arr[i] > max) max = arr[i];
//     }
//     cout << max;
// }

// #include <iostream>
// #include <string> //string 문자열
// #include <cstdio> //gets함수

// using namespace std;

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     string s1;
//     char s[20];

//     cin >> s1; // "abcd efg"
//     //gets(s); // "abcd efg" 둘 다 똑같음 출력은?
//     cout << s1;
//     cout << s;
// }

#include <iostream>
#include <string> //getline 함수
using namespace std;

int main(){
    
    string s;

    getline(cin, s);
    
    cout << s << endl;
    
    return 0;
}