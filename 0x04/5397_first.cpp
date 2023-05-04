/*
기본자료형 -> int, char, float, booleam
추가 지금까지 배운 자료형 -> 배열, 연결리스트 (5000기준으로 작으면 배열, 크면 연결리스트)
>> 배열, 연결리스트 -> 자료를 왔다갔다 다니면서 각 자료에 접근(삽입, 삭제) 느낌으로 기억

*/
#include <iostream>
#include <list>
#include <string>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;

    cin >> count; // 2번.
    for (int i = 0; i<count; i++)
    {
        list<char> li;
        // 1. vc++에서는 안되는 빈문자열
        li = {};
        // 2. li.clear(); //빈문자열 -> 왜인지 자꾸 에러남. clear 대신 반복문마다
        string s;
        auto cursor = li.begin();
        cin >> s;
        for (auto temp : s){ // -> 이 부분 생각이 어렵.  list는 빈문자열로 하고 s를 하나하나 돌면서 처리해줄 것 -> 큰 흐름!
            if (temp == '<'){
                if (cursor != li.begin()) cursor--; //ptr이랑 temp를 분리해서 생각하니 가능한 일!!
            }
            else if (temp == '>'){
                if (cursor != li.end()) cursor++;
            }
            else if (temp == '-'){ //begin 예외사항 생각 못 함
                if (cursor != li.begin()){
                cursor--;
                cursor= li.erase(cursor); //어차피 erase하고 난 다음 주소를 가리키는 걸 리턴하기에 cursor위치는 변동없음
                }
            }
            else{
                li.insert(cursor, temp);
            }

        }
        for (auto temp : li){ // 출력도 이 안에서
        cout << temp;
        }
        cout << '\n';
    }
}