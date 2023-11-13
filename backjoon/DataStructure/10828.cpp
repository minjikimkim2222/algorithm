#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int count;
    string input;
    int num;

    
    cin >> count;

    stack<int> st;

    while (count--){
        cin >> input;

        if (input == "push"){
            cin >> num;
            st.push(num);        
        }
        else if (input == "pop"){
            if (st.empty() == true)
                cout << "-1\n";
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (input == "size"){
            cout << st.size() << '\n';
        }
        else if (input == "empty"){
            cout << st.empty() << '\n';
        }
        else { // top
            if (st.empty() == true)
                cout << "-1\n";
            else {
                cout << st.top() << '\n';
            }
        }
    }


}