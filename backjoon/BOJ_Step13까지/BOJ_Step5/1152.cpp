/*
문자열 입력받기, cin vs getline 차이 , 공백여부
    링크 : https://velog.io/@sw801733/C-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%9E%85%EB%A0%A5-%EB%B0%9B%EA%B8%B0
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    int word_count = 0;

    getline(cin, str);

    for (int i = 0; i < str.length(); i++){
        if (i == str.length()-1 && (str[str.length() - 1] != ' '))
            word_count++;
        if (str[i] != ' ' && (i != str.length() - 1 && str[i+1] == ' ')){ // 문자열 index가 문자열 끝을 벗어날까봐 조건 추가
            word_count++;
        }
        
    }
    cout << word_count;
    
}