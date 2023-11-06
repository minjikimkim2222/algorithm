/*
이 방식 이외의, 문자열을 뒤에서부터 비교하는 관점도 가능!
*/
// #include <iostream>
// #include <algorithm> // swap함수, sort함수

// using namespace std;

// string reverse(string);
// int stringToInt(string);

// int main(void)
// {
//     string str1;
//     string str2;
//     int num1;
//     int num2;

//     cin >> str1 >> str2;

//     str1 = reverse(str1); 
//     str2 = reverse(str2);
    
//     num1 = stringToInt(str1);
//     num2 = stringToInt(str2);

//     if (num1 > num2)
//         cout << num1;
//     else
//         cout << num2;

// }

// int stringToInt(string s) // 734
// {
//     int result = 0;
//     int hundred = 100;
//     for (int i = 0; i < s.length(); i++){
//          result += (s[i] - 48) * hundred;
//          hundred /= 10;
//     }
//     return (result);
// }

// string reverse(string s)
// {
//     for (int i = 0; i <=  (s.length()-1) / 2; i++){
//         swap(s[i], s[(s.length()-1) - i]);
//     }
//     return (s);
// }

/*
    문자열을 뒤에서부터 비교하는 관점도 가능!
*/

#include <iostream>

using namespace std;

int main(void)
{
    string str1;
    string str2;
    string ret;

    cin >> str1 >> str2; // 893 734, 734 754  ,734 634

    for (int i = 2; i >= 0; i--){ // 문자열 거꾸로 비교
        if (str1[i] > str2[i]){
            ret = str1;
            break;
        }
        else if (str1[i] < str2[i]){
            ret = str2;
            break;
        } 
    }

    cout << ret[2] << ret[1] << ret[0];
}
