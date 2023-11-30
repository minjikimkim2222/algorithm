#include <iostream>
#include <deque> // deque stl
#include <string>

using namespace std;

int main(void)
{
    deque<int> DQ;
    int count;
    string command;

    cin >> count;

    int num;
    while (count--){
        cin >> command;

        if (command == "push_front"){
            cin >> num;
            DQ.push_front(num);
        }

        else if (command == "push_back"){
            cin >> num;
            DQ.push_back(num);
        }

        else if (command == "pop_front"){
            if (DQ.empty())
                cout << "-1" << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }

        else if (command == "pop_back"){
            if (DQ.empty())
                cout << "-1" << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }

        else if (command == "size"){
            cout << DQ.size() << '\n';
        }

        else if (command == "empty"){
            cout << DQ.empty() << '\n';
        }

        else if (command == "front"){
            if (DQ.empty())
                cout << "-1" << '\n';
            else
                cout << DQ.front() << '\n';
        }

        else if (command == "back"){
            if (DQ.empty())
                cout << "-1" << '\n';
            else
                cout << DQ.back() << '\n';
        }

    }
}