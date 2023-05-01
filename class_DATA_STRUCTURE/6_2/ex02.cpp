// 리스트를 구현 2. 단순 연결리스트 + 헤드노드 이용 (연결리스트 -> 단순, 원형, 이중)

#include <iostream>
#define MAX_LIST_SIZE 100
using namespace std;

inline void error(char *str)
{
    cout << stderr << str << endl;
    exit(1);
};

class Node
{
    public:
        int data;
        Node* link;
    public:
        Node(int val = 0) : data(val), link(NULL) {}
        Node* getLink() {return link;}
        void setLink(Node *next) {link = next;}
        void display() {cout << data << endl;}
        bool hasData(int val) {return data == val;}

        void insertNext(node* n)
        {
            if (n != NULL)
            {
                n -> link = link;
                link = n;
            }
        }

        Node* removeNext()
        {
            Node* removed = link;
            if (removed != NULL) // 내가 뭔가 가리키고는 있어
            {
                link = removed -> link;
            }
            return (removed);
        }


};
