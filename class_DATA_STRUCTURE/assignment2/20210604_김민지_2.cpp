/* 
총 5문제이며 6점 만점입니다. 

제출시 파일 명을 "학번_이름_2"으로 변경하여 결과 화면 캡쳐와 함께 압축하지 말고 제출하세요. 

파일명 미 변경 혹은 명세에 따라 작성하여 실행한 결과 화면을 첨부 하지 않을 시 0점 처리 됩니다.

또한 제출한 코드가 컴파일 혹은 실행이 되지 않을 경우 역시 0점 처리 됩니다.

주어진 테스트 코드는 예시이며 채점 시 사용하는 코드와 다소 상이할 수 있습니다.

** 주석 처리 된 부분 이외에 코드 영역 변경시 점수에 불이익이 있을 수 있습니다. **
*/

#include <iostream>
#include <utility>
using namespace std;

template <class K, class E>
class BinaryTree;

template <class K, class E>
class TreeNode
{
	friend class BinaryTree<K, E>;

private:
	TreeNode<K, E> *left;
	TreeNode<K, E> *right;
	pair<K, E> data;

public:
	TreeNode(pair<K, E> a)
	{
		left = 0;
		right = 0;
		data = a;
	}
};

template <class K, class E>
class BinaryTree
{
private:
	TreeNode<K, E> *root;

public:
	void Visit(TreeNode<K, E> *currentNode) { 	cout << currentNode->data.second << " "; }
	
    void Insert(const pair<K, E> &thePair);         //1)

    void Preorder();                                //2)
	void Preorder(TreeNode<K, E> *currentNode);     //2)
	
	void Inorder();                                 //3)
	void Inorder(TreeNode<K, E> *currentNode);      //3)
	
	void Postorder();                               //4)
	void Postorder(TreeNode<K, E> *currentNode);    //4)
	
	pair<K, E> *Get(const K &k);                    //5)
	pair<K, E> *Get(TreeNode<K, E> *p, const K &k); //5)
};

//1) (2점)
template <class K, class E>
void BinaryTree<K, E>::Insert(const pair<K, E> &thePair)
{
	TreeNode<K,E>	*currentNode = root; // 삽입할 노드를 가리킬 포인터 초기화	
	TreeNode<K,E> 	*parentNode = NULL; // 트리를 탐색하여 삽입할 위치 찾기
	
	while (currentNode != NULL) // 트리 순회 조건
	{
		if (thePair.first < currentNode -> data.first) // 키 비교해서 왼쪽 자식으로 이동
		{
			parentNode = currentNode;
			currentNode = currentNode -> left;
		}
		else if (thePair.first > currentNode -> data.first) // 키 비교해서 오른쪽 자식으로 이동
		{
			parentNode = currentNode;
			currentNode = currentNode -> right;
		}
		else // 동일한 키를 가진 노드가 이미 존재하는 경우, 데이터 업데이트
		{
			currentNode -> data.second = thePair.second;
		}
	}

	TreeNode<K,E> *new_Node = new TreeNode<K,E>(thePair);

	if (parentNode != NULL) // 트리가 비어있지 않은 경우
	{
		if (thePair.first < parentNode -> data.first) // 삽입할 위치에 맞게 부모 노드의 왼쪽
			parentNode -> left = new_Node;
		else
			parentNode -> right = new_Node;
	}
	else // 트리가 빈 경우 -> 새 노드를 루트에 지정 (맨처음에 parentptr == nullptr이라고 했음)
	{
		root = new_Node;
	}
   
}
//--------------------------------------------------------------------------------------

//2) (1점)
template <class K, class E>
void BinaryTree<K, E>::Preorder() 
{
    // Preorder Driver에 해당, 여기서는 preorder를 호출만 하고, 실제 수행은 workhorse에서 한다.
    // workhorse(rootnode) 호출
	Preorder(root);
}

template <class K, class E>
void BinaryTree<K, E>::Preorder(TreeNode<K, E> *currentNode) 
{
	if (currentNode != NULL) // 현재 노드가 존재하는 경우
	{
		Visit(currentNode); // 현재 노드 방문
		Preorder(currentNode -> left); // 왼쪽 서브트리를 전위순회
		Preorder(currentNode -> right); // 오른쪽 서브트리를 전위 순회
	}

}
//--------------------------------------------------------------------------------------

//3) (1점)
template <class K, class E>
void BinaryTree<K, E>::Inorder() 
{
    // Inorder Driver
    // workhorse(rootnode) 호출
	Inorder(root);
}

template <class K, class E>
void BinaryTree<K, E>::Inorder(TreeNode<K, E> *currentNode)
{
	if (currentNode != NULL)
	{
		Inorder(currentNode -> left);
		Visit(currentNode);
		Inorder(currentNode -> right);
	}
}
//--------------------------------------------------------------------------------------

//4) (1점)
template <class K, class E>
void BinaryTree<K, E>::Postorder()
{
    // Postorder Driver
    // workhorse(rootnode) 호출
	Postorder(root);
}

template <class K, class E>
void BinaryTree<K, E>::Postorder(TreeNode<K, E> *currentNode)
{
	if (currentNode != NULL)
	{
		Postorder(currentNode -> left);
		Postorder(currentNode -> right);
		Visit(currentNode);
	}
}
//--------------------------------------------------------------------------------------

//5) (1점)
template <class K, class E>
pair<K, E> *BinaryTree<K, E>::Get(const K &k)
{
    // Get Driver
    // workhorse(키값 k) 호출
	return (Get(root, k));
}

template <class K, class E>
pair<K, E> *BinaryTree<K, E>::Get(TreeNode<K, E> *p, const K &k)
{
	if (p == NULL) // 현재 노드 존재하지 않음
	{
		throw "찾는 노드가 존재하지 않는다";
	}

	else if (k < p -> data.first) // 키 비교하여 왼쪽 서브트리로 이동
	{
		return (Get(p->left, k));
	}

	else if (k > p -> data.first) // 키 비교해서 오른쪽 서브트리로 이동
	{
		return (Get(p->right, k));
	}
	else // 노드를 찾았다! 데이터를 반환해야 함
	{
		return (&(p -> data)); // 반환형이 포인터임. 주소연산자 붙이기
	}
    /*
    - 현재 노드가 존재하지 않는 경우 예외 처리	
	- 키 비교하여 왼쪽 또는 오른쪽 서브트리로 이동
	- 노드를 찾은 경우 데이터 반환
	*/
}
//--------------------------------------------------------------------------------------

int main()
{
	BinaryTree<int, int> tree = BinaryTree<int, int>();
	cout << "Insert TreeNode 8,4,9,2,1,6,3,5,7" << endl;
	tree.Insert(pair<int, int>(8, 88));
	tree.Insert(pair<int, int>(4, 44));
	tree.Insert(pair<int, int>(9, 99));
	tree.Insert(pair<int, int>(2, 22));
	tree.Insert(pair<int, int>(1, 11));
	tree.Insert(pair<int, int>(6, 66));
	tree.Insert(pair<int, int>(3, 33));
	tree.Insert(pair<int, int>(5, 55));
	tree.Insert(pair<int, int>(7, 77));
	
	cout << endl;
	cout << "Inorder : " ;
	tree.Inorder();
	cout << endl;
	cout << "Preorder : " ;
	tree.Preorder();
	cout << endl;
	cout << "Postorder : " ;
	tree.Postorder();
	cout << endl;
	cout << endl;
	
	try
	{
		cout << "Check if Node 10 exists" << endl;
		cout << tree.Get(10)->second << endl
			 << endl;
	}
	catch (const char *err)
	{
		cout << err << endl;
	}
	cout << endl;
	try
	{
		cout << "Check if Node 9 exists" << endl;
		cout << tree.Get(9)->second << endl;
	}
	catch (const char *err)
	{
		cout << err << endl;
	}

	return 0;
}
