// 좀 더 빠른 split ver2

// erase 대신, start와 end 초기화
#include <bits/stdc++.h>

using namespace std;

vector<string> splitv2(string input, string delimiter){
    vector<string> ret;
    auto start = 0;
    auto end = input.find(delimiter); // 3

    while (end != string::npos){
        ret.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start); // start이후부터 찾아야, 첫번째 인덱스 다시 안걸리지!!
    }
    ret.push_back(input.substr(start)); // string 안 지웠으니깐..

    return ret;
}

int main(void){
    string str = "abc,def,fse";
    vector<string> ret = splitv2(str, ",");
    
    for (string a : ret){
        cout << a << '\n';
    }

}