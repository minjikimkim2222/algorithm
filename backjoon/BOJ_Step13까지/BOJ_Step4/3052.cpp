#include <iostream>

using namespace std;

int main(void)
{
    int arr[10]; // 10개의 수를 담을 배열
    int count; // 다른 개수
    int sameCount = 0; // 같은 개수 
    for (int i = 0; i < 10; i++){
        cin >> arr[i];
        arr[i] = arr[i] % 42;
    }
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            if (arr[i] == arr[j]){
                sameCount++;
                break;
            }
        }
    }
    count = 10 - sameCount;
    cout << count;
    return (0);
}

/*
42개의 배열을 만들고, 처음에 0으로 초기화시킨 다음, 
해당 나머지 index 배열을 증가시킨다.
0이상인 경우 count return

참고 : https://st-lab.tistory.com/272
*/