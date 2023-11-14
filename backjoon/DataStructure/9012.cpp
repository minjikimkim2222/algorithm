#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    int count;
    int flag = 0;
    string line;

    cin >> count;

    while (count--){
       cin >> line;
       
       stack<char> st; // stack이 매 시도마다 초기화되어야 함
       for (int i = 0; i < line.length(); i++){
            
            if (line[i] == '('){
                st.push('(');
            }
            else { // ')'
                if (st.empty() == false && st.top() == '('){
                    st.pop();
                }
                else{ // st.empty인데 )이 들어온 경우 
                    flag = 1;
                }
            }
       }

       if (flag == 1){
            cout << "NO\n";
       }
       else if (st.empty() == true){
            cout << "YES\n";
       }
       else if (st.empty() == false){
            cout << "NO\n";
       }
       
       flag = 0;
    }
}