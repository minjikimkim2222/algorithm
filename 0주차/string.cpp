#include <bits/stdc++.h>

using namespace std;

int main(void){
    string input = "minjiki2222";

    // substr 함수 테스트
    string ret1 = input.substr(1, 3);
    string ret2 = input.substr(3);

    cout << "==== substr test ======" << '\n';
    cout << ret1 << '\n';
    cout << ret2 << '\n';

    // find 함수 테스트
    string findstr = "22"; // 찾을 부분문자열
    int pos = 0; // 검색 시작 인덱스

    cout << "==== find test ======= " << '\n';
    int retIdx = input.find(findstr, pos);
    cout << "해당 부분문자열 시작 위치 : " << retIdx << '\n';
}