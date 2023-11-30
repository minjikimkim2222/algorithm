#include <iostream>
#include <queue> // queue stl
#include <string>

using namespace std;

int main(void)
{
    queue<int> Q;
    int count;
    
    cin >> count;
    
    string command;
    int pushNum;
    while (count--){
        cin >> command;
        
        if (command == "push"){
            cin >> pushNum;
            Q.push(pushNum);
        }

        else if (command == "pop"){
            if (Q.empty() == true){
                cout << "-1" << '\n'; 
            }
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }

        else if (command == "size"){
            cout << Q.size() << '\n';
        }

        else if (command == "empty"){
            cout << Q.empty() << '\n';
        }

        else if (command == "front"){
            if (Q.empty() == true)
                cout << "-1" << '\n';
            else {
                cout << Q.front() << '\n';
            }
        }

        else { // back
            if (Q.empty() == true){
                cout << "-1" << '\n';
            }
            else {
                cout << Q.back() << '\n';
            }
        }
    }
}