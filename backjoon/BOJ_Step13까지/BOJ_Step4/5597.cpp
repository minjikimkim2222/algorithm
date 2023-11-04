#include <iostream>

using namespace std;

int main(void)
{
    int n; // 출석번호
    bool isSummit[31]; // 1 ~ 30번 제출여부 저장

    for (int i = 1; i <= 30; i++)
        isSummit[i] = false; // 전부 제출안함으로 초기화
    
    for (int i = 0; i < 28; i++){
        cin >> n;
        isSummit[n] = true; // 해당 출석번호는 제출함
    }

    // 1번 ~ 30번까지, 28명은 true, 2명은 false

    for (int i = 1; i <= 30; i++){
        if (isSummit[i] == false){
            cout << i << '\n';
        }
    }
}