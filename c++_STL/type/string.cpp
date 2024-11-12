// string에서 자주 쓰이는 메서드들

#include <bits/stdc++.h>

using namespace std;

int main(void){
    string a = "love is";

// 1. 문자열 더하고 빼기
    // += -> 보통 문자열을 더할 때 씀
    a += " pain!";
    a.pop_back(); // "love is pain" , 문자열 끝을 지움

// 2. 문자열 크기, 시작위치, 끝위치
    cout << a.size() << '\n'; // 12
    
    cout << *(a.begin()) << '\n'; // l
    cout << *(a.end() -1 ) << '\n'; // n ; end()는 문자열 끝을 가리키니까

// 3. 문자열 삽입/삭제
    cout << a.insert(3, "insert1") << '\n'; // lovinsert1e is pain
    cout << a.erase(0, 5) << '\n'; // sert1e is pain


}