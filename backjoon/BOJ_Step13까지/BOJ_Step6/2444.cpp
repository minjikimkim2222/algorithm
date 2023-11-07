// 문제를 쪼개는 생각!
// 예제 그림 3등분하기

#include <iostream>

using namespace std;

void firstPart(int n);
void secondPart(int n);
void lastPart(int n);

int main(void)
{
    int N;
    
    cin >> N; // 5
    firstPart(N);
    secondPart(N);
    lastPart(N);

}

void firstPart(int n) // 5
{
    for (int i = 0; i < n-1; i++){
        // 각 라인마다 별을 출력하는 코드
        for (int j = n - i - 1; j > 0; j--){ // 공백 출력 코드
            cout << " ";
        }
        for (int j = 0; j <= (2*i); j++){
            cout << "*";
        }
        // 한 줄 출력한 뒤, 한 줄 내리기
        cout << '\n';
    }
}

void secondPart(int n)
{
    for (int i = 0; i <= 2 * (n-1); i++)
        cout << "*";
    cout << '\n';
}

void lastPart(int n) // firstPart를 거꾸로
{
    for (int i = 1; i < n; i++){ // i : 1, 2, 3, 4 (한줄 덜 출력)
        // 각 라인마다 줄 (공백 + *)
        for (int j = 0; j < i; j++){ 
            cout << " ";
        }
        for (int j = 2*(n-i)-1; j > 0 ;j--) // j = 7, 5, 3, 1, n = 5
        {
            cout << "*";
        }
        // 각 라인마다 개행
        cout << '\n';
    }
}