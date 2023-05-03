#include <iostream>

using namespace std;

inline void error(char *str)
{
    cerr << str << endl;
    exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue {
    protected:
        int front;
        int rear;
        int data[MAX_QUEUE_SIZE];

    public:
    CircularQueue() {
        front = rear = 0;
    }
    ~CircularQueue(){       
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_QUEUE_SIZE == front;
    }

    void enqueue(int val)
    {
        if (isFull())
            error(" error : 큐가 포화상태이다\n");
        else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    int dequeue()
    {
        if (isEmpty())
            error("error : 큐가 공백상태이다\n");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    int peek()
    {
        if (isEmpty())
            error(" error : 큐가 공백상태이다\n");
        else
        {
            return data[(front + 1) % MAX_QUEUE_SIZE];
        }
    }

    void display()
    {
        cout << " 큐 내용 :";
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            cout << "[" << data[i % MAX_QUEUE_SIZE] << "]";
        cout << endl;
    }
};

class CircularDeque : public CircularQueue{

    public :
        CircularDeque() {}
        void addRear(int val) {enqueue(val);}
        int deleteFront() {return dequeue();}
        int getFront() {return peek();}
        // 위에서는 기존 원형 큐에 있던 연산 이용.
        // 아래부터는 덱 연산에서 추가되는 연산들 구현
        void addFront(int val)
        {
            if (isFull())
                error(" error : 덱이 포화상태이다\n");
            else{
                data[front] = val;
                front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }

        int deleteRear(){
            if (isEmpty())
                error(" error : 덱이 공백상태이다\n");
            else{
                int ret = data[rear];
                rear = (rear -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return (ret);
            }
        }

        int getRear(){
            if (isEmpty())
                error(" error : 덱이 공백상태이다\n");
            else
                return (data[rear]);
        }

        void display(){
            cout << "덱의 내용 : ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            for (int i = front + 1; i <= maxi; i++)
                cout << "[" << data[i % MAX_QUEUE_SIZE] << "]";
            cout << endl;
        }
};

int main(void){
    CircularDeque deq;
    for (int i = 1; i < 10; i++){
        if (i % 2) deq.addFront(i);
        else deq.addRear(i);
    }
    deq.display();

    deq.deleteFront();
    deq.deleteRear();
    deq.deleteFront();
    deq.display();
}