#include <iostream>

using namespace std;
// 이것도 뭔가 쉬운데 왜 ?  이러지 말고, 아는 걸 최대한 단순화시켜야 풀 수 있는거임.
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int result[26] = {0};
    int i = 0;

    cin >> s;
    while (s[i]){
        result[s[i] - 97]++;
        i++;
    }
    for (int i = 0; i < 26; i++){
        cout << result[i] << ' ';
    }
    cout << "\n";
}