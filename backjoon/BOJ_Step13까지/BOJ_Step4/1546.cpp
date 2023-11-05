/*
정수 연산이 아닌 실수 연산이 필요하다는 것.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n; // 시험 본 과목의 개수
    double score[1002]; // 과목 점수 저장 배열, 실수 계산을 위해
    double max; // 최고점
    double sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> score[i];
    
    sort(score + 0, score + n); // 0 ~ n-1까지 정렬 (sort, 포함 ~ 미포함)

    max = score[n-1];
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + (score[i] / max) * 100;
    }
    cout << sum / n; // 평균

   
}