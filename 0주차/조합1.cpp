#include <bits/stdc++.h>

using namespace std;

// 5C3 -- 5개 중, 3개를 뽑는 경우의 수를 구해보자!

int n = 5, r = 3, a[5] = {1,2,3,4,5};

void print(vector<int> b){
    for (int data : b)
        cout << data << ' ';
    cout << '\n';
}

void f(int start, vector<int> b){
    if (b.size() == r){
        print(b);
        return;
    }

    for (int i = start + 1; i < n; i++){
        b.push_back(i);
        f(i, b);
        b.pop_back(); // 복원
    }
    return ;
}

int main(void){
    vector<int> b;
    f(-1, b);
    return 0;
}