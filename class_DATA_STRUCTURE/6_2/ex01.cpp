// 리스트 구현 1. 배열

#include <iostream>
#define MAX_LIST_SIZE 100
using namespace std;

inline void error(char *str)
{
    cout << stderr << str << endl; //cout은 stderr(표준파일디스크립터 중 하나)라는 파일에 str을 출력한다
    exit(1);
};

class ArrayList
{
    int data[MAX_LIST_SIZE];
    int length;

    public :
    ArrayList(void) {length = 0;}
    
    void insert(int pos, int e)
    {
        if (!isFull() && pos >= 0 && pos <= length)
        {
            for (int i = length; i > pos; i--)
                data[i] = data[i-1];
            data[pos] = e;
            length++;
        }
        else error("포화상태 오류 또는 삽입 위치 오류");
    }

    void    remove(int pos)
    {
        if (!isEmpty() && pos >= 0 && pos < length)
        {
            for (int i = pos + 1; i < length; i++)
                data[i-1] = data[i];
            length--;
        }
        else error ("공백상태 오류 또는 삭제 위치 오류");
    }

    int getEntry(int pos) {return data[pos];}

    bool isEmpty() {return (length == 0);}
    bool isFull() {return (length == MAX_LIST_SIZE);}

    bool find(int item)
    {
        for (int i = 0; i < length; i++)
            if (data[i] == item)
                return (true);
        return (false);
    }

    void replace(int pos, int e)
    {
        data[pos] = e;
    }

    int size() {return (length);}

    void display()
    {
        cout << "배열로 구현한 리스트 전체 항목의 수" <<length<<endl;
        for (int i = 0; i < length; i++)
        {
            cout << "[" << data[i] << "]";
            cout << endl;
        }
    }

    void clear() {length = 0;}

};

int main()
{
    ArrayList list;

    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(1, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();

    // 20, 30, 50, 10, 40

    list.remove(2); // 20, 30, 10, 40
    list.remove(list.size() - 1); // length--로, length 가 3이 되어, 20, 30, 10으로 인식
    list.remove(0); // 30, 10
    list.replace(1, 90); // 30, 90
    list.display();

    list.clear();
    list.display();
}


