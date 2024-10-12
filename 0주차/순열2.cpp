/*
    순열1에서 next_permutation으로 순열을 만들었다면,
    순열2에서는 재귀함수로 순열 만드는 법 
        -> 간단한 재귀함수 틀이니까 외워두기!   
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> v = {1,2,3};

void printV(vector<int> v){
    for (int data : v){
        cout << data << " ";
    }
    cout << '\n';
}

void f(int n, int r, int depth){
    if (r == depth){
        // 기저조건에서의 로직 !!
        printV(v); // 최종 vector 출력
        return;
    }

    for (int i = depth; i < n; i++){
        swap(v[i], v[depth]); // 진짜 swap시킴
        f(n, r, depth + 1);
        swap(v[i], v[depth]); // 원래 vector 형태로 복원
    }
}

int main(void){
    f(3,3,0);
}