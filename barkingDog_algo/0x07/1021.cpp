#include <iostream>
#include <deque>
/*
1. 간단하게 왼쪽 오른쪽 나누는 기준 = key_idx VS DQ.size() / 2 , 사이즈의 평균보다 찾는 값이 왼쪽인지 오른쪽인지

2. 간단하게 생각해라
    입력을 매번 받으니까 매번 받는 cin >> num을 만드는 게 쉽잖아. 굳이 왜 배열을 만들어서 탐색을 할 생각을 해!!!
*/
using namespace std;

deque<int> DQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size, find;
    cin >> size; // 10
    cin >> find; // 3

    for (int i = 0; i < size; i++)
        DQ.push_back(i+1);
    // input complete 1 ~ 10, ->> ok
    
    int key_idx;
    int num;
    int count = 0;

    while (find--) // while조건을 좀 더 "쉽게" find로 수정!!
    {
        cin >> num; // 매번 while문 마다 찾을 정수 입력받을 것! [입력, while문 조건]
        
        for (int i = 0; i < DQ.size(); i++)
        {
            if (num == DQ[i]){
                key_idx = i;
                break; // 찾으면 나가라!
            }
        } 

        if (key_idx < DQ.size() - key_idx) // 이 조건은 왜? 왜 key_idx < DQ.size() / 2가 아니지?
        {
            while (1) //left
            {
                if (DQ.front() == num){
                    DQ.pop_front();
                    break;
                }
                ++count;
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
        }
        else{
            while (1){
                if (DQ.front() == num){
                    DQ.pop_front();
                    break;
                }
                ++count;
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
        }
    }
    cout << count << '\n';
}
