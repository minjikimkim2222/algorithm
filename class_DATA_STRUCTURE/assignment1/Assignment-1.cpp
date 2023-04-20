/* 
총 2문제이며 5점 만점입니다. 

제출시 파일 명을 "학번_이름_1"으로 변경하여 결과 화면 캡쳐와 함께 압축하지 말고 제출하세요. 

파일명 미 변경 혹은 명세에 따라 작성하여 실행한 결과화면을 첨부 하지 않을 시 0점 처리 됩니다.

또한 제출한 코드가 컴파일 혹은 실행이 되지 않을 경우 역시 0점 처리 됩니다.

주어진 테스트 코드는 예시이며 채점 시 사용하는 코드와 다소 상이할 수 있습니다.
*/

#include <iostream>

using namespace std;

//1번 (1점)
// int형 변수를 생성하여 입력받은 두 변수의 값을 서로 변경하는 함수를 작성
// 단, 함수 오버로딩을 활용하여 아래의 main 함수의 테스트 코드를 참고하여 호출 format에 맞게 두가지 다른 함수로 작성

void swap ( int* a, int* b)
{
  // int형 변수를 생성하여 입력받은 두 변수의 값을 서로 변경하는 함수를 작성하세요.
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swap ( int& a, int& b)
{
  // int형 변수를 생성하여 입력받은 두 변수의 값을 서로 변경하는 함수를 작성하세요.
  int temp = a;
  a = b;
  b = temp;
}



//-----------------------------------------------------------------------------------------------

//2번
// 아래 Node, Stack class의 함수 선언부를 보고 함수들을 완성하세요.

class Node
{
  public :
    int data;
    Node * link;
    Node(int data)
    {
      this->data = data;
      this->link = nullptr;
    }
};

class Stack
{
  private:
    Node * top;

  public:
    Stack(); // Stack의 생성자로 top node 를 nullptr로 초기화 합니다.
    ~Stack();// Stack의 소멸자로 생성된 모든 노드를 delete 합니다.
    void push(int value); // value 값을 data로 가지는 node를 새로 추가합니다.
    int pop(); // 가장 위에 있는 top 노드를 삭제합니다.
    int peek(); // top 노드의 data 값을 반환합니다.
    bool isEmpty(); // 해당 stack이 비어있는지 확인합니다.
    
};

//2-1 (1점)
Stack::Stack() 
{ 
  // stack class의 생성자로 top node를 초기화;
  this -> top = nullptr;
}

Stack::~Stack()
{
  // stack class의 소멸자로 stack에 들어있는 모든 node들을 할당 해제 시킴.
  // 단, node 들을 할당 해제 할때 확인을 위해 해제 되는 node들의 data를 출력; ( ex) "delete 1" )

  Node* cur = top; //이제부터 cur를 쓸 거다.
  while (cur != nullptr)
  {
    Node* temp = cur;
    cur = cur -> link;
    cout << "delete "<< temp -> data << endl; //삭제 node data 출력
    delete (temp);
  }
}

//2-2 (1점)
bool Stack::isEmpty() 
{ 
  // 해당 stack이 비어있는지 검사하는 함수로 top node가 비어있는지를 체크;
  return (top == nullptr);
}

int Stack::peek()
{
  // 해당 stack 객체가 비어있지 않으면 top node 객체의 data 반환;
  // 비어있는 경우 -1 반환;
  if (!isEmpty())
    return (top -> data);
  return (-1);
}

//2-3 (2점)
void Stack::push(int value)
{
  // 새로운 Node를 동적 할당하여 생성;
  // stack이 비어있다면 top에 새로운 노드 대입;
  // 비어있지 않다면 새 Node를 top node 다음으로 연결;
  // 이후 top node를 새 node로 지정;
  Node* node = new Node(value);
  if (isEmpty())
    top = node;
  else{
    node -> link = top;
    top = node;
  }
}

int Stack::pop()
 {
  // 비어있는 경우 -1 반환;
  // 새로운 int형 변수 선언후 top node의 data 저장;
  // 임시 Node 포인터 선언후 top node의 주소 저장;
  // top node를 한칸 아래로 이동;
  // 임시로 선언해둔 Node 포인터 할당 해제;
  // 이전 top node의 data를 저장한 int value 반환;
  if (isEmpty())
    return (-1);
  int data = top -> data;
  Node* temp = top;
  top = top -> link;
  delete temp;
  return (data);
 } 



//test 코드
int main()
{

  //학번과 이름이 나오도록 출력하세요.
  //ex) cout << "20180812 정진우"<<endl;
  cout << "20210604 김민지" << endl;
  //1번 문항
  int a = 1;
  int b = 2;
  cout << a << " " << b << endl;
  swap(&a,&b); //주소값 넘기도록 변경 -> 매개변수 자료형이 달라짐
  cout << a << " " << b << endl;

  int a1 = 10;
  int b1 = 20;
  int &c = a1;
  int &d = b1;
  cout << a1 << " " << b1 << endl;
  swap(c,d);
  cout << a1 << " " << b1 << endl;


  cout << " --------------------------------------------------"<<endl;
  //2번 문항
  
  Stack s;
  cout << s.peek()<<endl;
  s.push(1);
  cout << s.peek()<<endl;
  s.push(3);
  cout << s.peek()<<endl;
  s.pop();
  cout << s.peek()<<endl;
  s.push(4);
  cout << s.peek()<<endl;
  s.pop();
  cout << s.peek()<<endl;
  s.push(2);
  cout << s.peek()<<endl;
  s.push(7);
  cout << s.peek()<<endl;
}