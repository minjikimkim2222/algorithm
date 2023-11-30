// 에디터 -> 임의의 위치에 원소 추가, 삭제 -> 연결리스트 stl 활용
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
    string input;
    list<char> L;
    int count;

    cin >> input;
    for (int i = 0; i < input.length(); i++)
        L.push_back(input[i]);
    
    list<char>::iterator ptr = L.end();

    cin >> count;
    
    char command;
    char addChar;
    while (count--){
        cin >> command;
        
        if (command == 'L'){
            if (ptr == L.begin()){
                continue;
            }
            
            else {
                ptr--;
            }
        }

        else if (command == 'D'){
            if (ptr == L.end())
                continue;
            
            else {
                ptr++;
            }
        }

        else if (command == 'B'){
            if (ptr == L.begin()){
                continue;
            }
            else {
                ptr--; // 커서 왼쪽 이동 (연결리스트에서 li.end()는 맨 마지막 원소가 아닌, 맨 마지막 원소 바로 뒤니까 이거 안해주면 메모리할당 오류 났음!!)
                ptr = L.erase(ptr);
            }
        }

        else { // P $
            cin >> addChar;
            L.insert(ptr, addChar);
        }
    } 

    for (auto list : L)
        cout << list;

}