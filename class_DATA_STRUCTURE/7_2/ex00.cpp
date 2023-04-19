#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node (char data) : data(data), next(nullptr) { }
};

class Stack{
    private:
        Node* top;
    public:
        Stack() : top(nullptr) {}
        ~Stack() {
            Node* cur = top;
            while (cur != nullptr)
            {
                Node* tmp = cur;
                cur = cur -> next;
                delete tmp;
            }
        }
        void push(int data) //새로운 노드 추가
        {
            Node* node = new Node(data);
            node -> next = top;
            top = node;
        }

        char pop() // 삭제연산
        {
            if (isEmpty())
            {
                cout << "스택이 비었다." << endl;
                exit(1);
            }
            char temp = top -> data;
            Node *node = top;
            top = top -> next;
            delete node;
            return (temp);
        }

        char peek() //top 데이터 값 리턴
        {
            if (isEmpty())
            {
                cout << "스택 비어있다." <<endl;
                exit(1);
            }
            return (top -> data);
        }

        bool isEmpty()
        {
            return (top == nullptr);
        }
};

bool checkBracket(string str) //입력값의 괄호 검사 프로그램 구현
{
    Stack stack; //스택 자료구조 사용
    for (int i = 0; i < str.length(); i++) //문자열 끝까지
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') // 검사 문자가 여는 괄호 종류들이면,
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') //오른쪽 괄호 만나면, top 괄호 삭제 후, 왼쪽 괄호와 짝이 맞는지 체크
        {
            if (stack.isEmpty()) return false;
            char openCh = stack.pop();
            if ((ch == ')' && openCh != '(') || (ch == '}' && openCh != '{') || (ch == ']' && openCh != '['))
            {
                return (false); //짝이 안 맞으면, 거짓
            }
        }
    }
    return (stack.isEmpty()); //마지막 검사 다했는데도 남아있다면, 왼,오 괄호 개수 짝이 안 맞는다는 의미

}

int main()
{
    string str = "{(a+b)*c} -d";
    if (checkBracket(str)){
        cout << "괄호 체크 맞아요" << endl;
    }

    else 
    {
        cout << "괄호 체크 틀렸어요" << endl;
    }
    return (0);
}