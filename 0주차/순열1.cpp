/*
    순열 만들기 1) c++ 제공, next_permutation

    제한조건 :: 배열이 오름차순으로 정렬되어 있어야 함.
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    // 이번엔 5개 중, 순서 관계있게, 2개 뽑기 !! == 5P2
    vector<int> v = {2,3,1,100,200};

    sort(v.begin(), v.end());

    do {
        for (int i = 0; i <= 1; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
}


