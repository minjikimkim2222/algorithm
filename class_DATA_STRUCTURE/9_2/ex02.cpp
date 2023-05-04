#include <iostream> 
#define MAX_STACK_SIZE 100
using namespace std;

inline void error(char* str) {
cout << str << endl;
exit(1); };

class Node2 { 
    Node2* prev;
    Node2* next;
    int data; 
public:
    Node2(int val = 0) : data(val), prev(nullptr), next(nullptr) {} Node2* getPrev() { return prev; }
    Node2* getNext() { return next; }
    void setPrev(Node2* p) { prev = p; }
    void setNext(Node2* n) { next = n; }
    void display() { cout << " <" << data << ">"; } bool hasData(int val) { return data == val; }

void insertNext(Node2* n) 
{ if (n != nullptr) { n->prev = this; n->next = next;
if (next != nullptr) next->prev = n;
next = n; }
}

Node2* remove() {
if (prev != nullptr) prev->next = next; if (next != nullptr) next->prev = prev; return this;
} 
};

class DblLinkedList 
{ 
    Node2 org;
public:
    DblLinkedList() : org(0) {} 
    ~DblLinkedList() { clear(); }

    void clear() { while (!isEmpty()) delete remove(0); } 
    Node2* getHead() { return org.getNext(); }
    bool isEmpty() { return getHead() == nullptr; }

    Node2* getEntry(int pos) {
    Node2* n = &org;
    for (int i = -1; i < pos; i++, n = n->getNext())
        if (n == nullptr) break; 
    return n;}

void insert(int pos, Node2* n) 
{ 
    Node2* prev = getEntry(pos - 1); 
    if (prev != nullptr)
        prev->insertNext(n);
}

    Node2* remove(int pos) { 
        Node2* n = getEntry(pos);
        return n->remove();
}

Node2* find(int val) {
    for (Node2* p = getHead(); p != nullptr; p = p->getNext())
        if (p->hasData(val)) return p; return nullptr;
}

void replace(int pos, Node2* n) { 
    Node2* prev = getEntry(pos - 1); 
    if (prev != nullptr) {
    delete prev->getNext()->remove();
    prev->insertNext(n); }
}

int size() {
int count = 0;
for (Node2* p = getHead(); p != nullptr; p = p->getNext())
count++; return count;
}
void display() {
cout << "[이중연결리스트 항목 수 = " << size() << "] : ";
for (Node2* p = getHead(); p != nullptr; p = p->getNext())
p->display(); cout << endl;
} 
};

class LinkedDeque : public DblLinkedList{
    public:
        void addFront(Node2* n) {insert(0, n);}
        Node2* deleteFront() {return remove(0);}
        Node2* getFront() {return getEntry(0);}
        void addRear(Node2* n) { insert(size(), n);}
        Node2* deleteRear() {return remove(size()-1);}
        Node2* getRear() {return getEntry(size() -1);}
};

int main(){
    LinkedDeque deq;
    for (int i = 1; i < 10; i++){
        if (i % 2)
            deq.addFront( new Node2(i) );
        else{
            deq.addRear(new Node2(i));
        }
    }
        deq.display();
        delete deq.deleteFront();
        delete deq.deleteRear();
        delete deq.deleteFront();
        deq.display();
}