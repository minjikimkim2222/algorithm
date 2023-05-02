#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c;
    int result;
    int tmp;

    int arr[10] = {0};
    cin >> a >> b >> c;
    result = a * b * c;
    tmp = result;

    for(int i =0; i<10;i++) //일단 i = 0, arr[0], 0의 개수부터 처리 후 넘어갈 것
    {
        result = tmp;
        while (result){
            if (result % 10 == i) arr[i] = arr[i] + 1;
            result = result / 10;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;
    
}

//기죽지 말고 뭔가 복잡하게 가고 있다면 다른 저장공간 배열을 생각해보기
//배열만 출력할래 -> 배열의 원소 각각에는 각 0 개수 몇개, 1 개수 몇개인지 확인만 할래. 
// 간단하게 원하는 값을 출력할 것에 넣도록! 생각