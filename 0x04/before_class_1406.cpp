/*
자료구조 2번. 연결리스트
문제유형은 이렇게 원소를 돌아다니다가 삽입, 삭제할 때 n = 5000 정도로 작다면 배열, 아니라면 연결리스트.
여기서는 연결리스트를 이용했다.
1. STL list 이용
*/
#include <iostream>
#include <list> // 연결리스트 stl 이용
#include <string> //string 문자열 타입 사용

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> li;
    string str;

    cin >> str; //"abcd"
    for (auto temp : str)
        li.push_back(temp);
    list<char>::iterator cursor = li.end(); // list의 주소 역할, iterator. auto ptr = li.end();도 가능
    /*
    cout << *(--ptr); //그냥 *ptr 시, 맨 마지막 원소가 아닌 맨 마지막 바로 다음 nullptr임. 
    따라서 맨 마지막 원소를 가리키고 싶다면("abcd"에서 'd') *(--ptr)하면 됨
    */
    int count;
    cin >> count; //명령어 반복 횟수
    for (int i =0; i< count; i++){
        char input;
        cin >> input;
        if (input == 'L'){
            if (cursor == li.begin())
                continue;
            cursor--;
        }
        else if (input == 'D'){
            if (cursor == li.end())
                continue;
            cursor++;
        }
        else if (input == 'B'){
            if (cursor == li.begin())
                continue;
            cursor--; // cursor 왼쪽 이동은 --가 맞다
            cursor = li.erase(cursor);
        }
        else if (input == 'P')
        {
            char c;
            cin >> c; //커서 왼쪽에 추가할 문자열
            li.insert(cursor, c); //cursor가 가리키는 곳에 c 삽입
        }
    }
    for (auto temp : li){
        cout << temp;
    }
}
