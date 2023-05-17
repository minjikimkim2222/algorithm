#include <iostream>

using namespace std;

inline void error(char *str)
{
    cerr << str << endl;
    exit(1);
};


class BinaryNode
{
    protected:
        int data;
        BinaryNode  *left;
        BinaryNode  *right;
    public:
        BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
            : data(val), left(l), right(r) { }
        ~BinaryNode() { }

        void        setData(int val) { data = val;}
        void        setLeft(BinaryNode* l) { left = l;}
        void        setRight(BinaryNode* r) {right = r;}
        int         getData() { return (data);}
        BinaryNode* getLeft() { return (left);}
        BinaryNode* getRight() { return (right);}
        bool        isLeaf() {return (left == NULL && right == NULL);}  

};

#define MAX_QUEUE_SIZE 100

class CircularQueue
{
    int front;
    int rear;
    BinaryNode* data[MAX_QUEUE_SIZE];
    public:
        CircularQueue() {front = rear = 0;}
        ~CircularQueue() { }
        bool isFull() {return (rear+1)%MAX_QUEUE_SIZE == front;}
        bool isEmpty() {return front == rear;}
        void enqueue(BinaryNode* n){
            if (isFull()) error ("Error : 큐가 포화다\n");
            else{
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = n;
            }
        }
        BinaryNode* dequeue(){
            if (isEmpty()) error("Error : 큐가 공백이다\n");
            else{
                front = (front + 1) % MAX_QUEUE_SIZE;
                return (data[front]);
            }
        }
};

class BinaryTree
        {
            public:
            BinaryNode* root;
            

                BinaryTree():root(NULL) { }
                ~BinaryTree() { }

                void    setRoot(BinaryNode* node) {root = node;}
                BinaryNode* getRoot() {return (root);}
                bool isEmpty() {return (root == NULL);}

                void    display()
                {
                    cout << "Binary Tree : " << endl;
                    if (isEmpty()){
                        cout << "Empty Tree." << endl;
                    }
                    else{
                        display(root, 0);
                    }
                }

void    inorder() {cout << "\n  inorder : "; inorder(root);}
void    inorder(BinaryNode* node)
{
    if (node != NULL)
    {
        inorder(node -> getLeft());
        cout << "[" << (node -> getData()) << "]";
        inorder(node -> getRight());
    }
}

void    preorder() {cout << "\n preorder : "; preorder(root); }
void    preorder(BinaryNode* node)
{
    if (node != NULL)
    {
        cout << "[" << (node -> getData()) << "]";
        preorder(node -> getLeft());
        preorder(node -> getRight());
    }
}

void    postorder() {cout << "\n postorder : "; postorder(root); }
void    postorder(BinaryNode* node)
{
    if (node != NULL)
    {
        postorder(node -> getLeft());
        postorder(node -> getRight());
        cout << "[" << (node -> getData()) << "]";
    }
}


                void levelorder(){
                    cout << "\n level order : ";
                    if (!isEmpty())
                    {
                        CircularQueue q;
                        q.enqueue(root);
                        while (!q.isEmpty()){
                            BinaryNode* n = q.dequeue();
                            if (n != NULL)
                            {
                                cout << "[" << (n -> getData()) << "]";
                                q.enqueue(n -> getLeft());
                                q.enqueue(n -> getRight());
                            }
                        }
                        cout << "\n";
                    }
                }

            private :
                void    display(BinaryNode* node, int depth){
                    if (node == NULL)
                        return ;
                    else{
                        for (int i = 0; i < depth; i++)
                            cout << " ";
                        cout << "- " << (node -> getData()) << endl;

                        display(node -> getLeft(), depth + 1);
                        display(node -> getRight(), depth + 1);
                    }
                }
};

class BinSrchTree : public BinaryTree
{
    public:
    BinSrchTree(void) { }
    ~BinSrchTree(void) { }

    BinaryNode* search(int key)
    {
        BinaryNode* node = search(root, key);
        if (node != NULL)
            printf("탐색 성공 : 키값이 %d인 노드 = 0x%p\n", node -> getData(), node);
        else
            printf("탐색 실패 : 키값이 %d인 노드 없음\n", key);
        return (node);
    }

    BinaryNode* search(BinaryNode*n, int key){
        if (n == NULL) return (NULL);
        if (key == n -> getData())
            return (n);
        else if (key < n -> getData())
            return (search(n->getLeft(), key));
        else
            return search(n->getRight(), key);
    }

    void insert(BinaryNode *n)
    {
        if (n == NULL) return;
        if (isEmpty())
            root = n;
        else
        {
            insert(root, n);
        }
    }
    
    void insert(BinaryNode* r, BinaryNode* n)
    {
        if (n -> getData() == r -> getData())
            return;
        else if (n -> getData() < r -> getData()){
            if (r -> getLeft() == NULL)
                r -> setLeft(n);
            else
                insert(r -> getLeft(),n);
        }
        else
        {
            if (r->getRight() == NULL)
                r -> setRight(n);
            else
                insert(r->getRight(), n);
        }
    }

    void remove(int data)
    {
        if (isEmpty()) return;
        BinaryNode* parent = NULL;
        BinaryNode* node = root;
        while (node != NULL && node -> getData() != data){
            parent = node;
            node = (data < node -> getData())
                ? node -> getLeft()
                : node -> getRight();
        }

        if (node == NULL){
            printf("Error : key is not in the tree!\n");
            return ;
        }
        else remove(parent,node);

    }

    void remove(BinaryNode* parent, BinaryNode* node)
    {
        //case1
        if (node -> isLeaf()){
            if (parent == NULL) root = NULL;
            else{
                if (parent -> getLeft() == node)
                    parent -> setLeft(NULL);
                else 
                    parent -> setRight(NULL);
            }
        }

        //case2
        else if (node -> getLeft() == NULL || node -> getRight() == NULL)
        {
            BinaryNode* child = (node -> getLeft() != NULL)
            ?node -> getLeft()
            : node -> getRight();

            if (node == root)
                root = child;
            else{
                if (parent -> getLeft() == node)
                    parent -> setLeft(child);
                else
                    parent -> setRight(child);
            }
        }

        //case3
        else{
            BinaryNode* succp = node;
            BinaryNode* succ = node -> getRight();
            while (succ -> getLeft() != NULL){
                succp = succ;
                succ = succ -> getLeft();
            }

            if (succp -> getLeft() == succ)
                succp -> setLeft(succ -> getRight());
            else
                succp -> setRight(succ -> getRight());
            node -> setData(succ -> getData());
            node = succ;
        }
        delete node;
    }


};

int main()
{
    BinSrchTree tree;

    tree.insert(new BinaryNode(35));
    tree.insert(new BinaryNode(18));
    tree.insert(new BinaryNode(7));
    tree.insert(new BinaryNode(26));
    tree.insert(new BinaryNode(12));
    tree.insert(new BinaryNode(3));
    tree.insert(new BinaryNode(68));
    tree.insert(new BinaryNode(22));
    tree.insert(new BinaryNode(30));
    tree.insert(new BinaryNode(99));

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    tree.search(26);
    tree.search(25);

    printf("삭제 : case1 -> node 3 delete");
    tree.remove(3);
    tree.levelorder();

    printf("삭제 : case2 -> node 68 delete");
    tree.remove(68);
    tree.levelorder();

     printf("삭제 : case3 -> node 18 delete");
    tree.remove(18);
    tree.levelorder();

     printf("삭제 : case4 -> node 35(root node) delete");
    tree.remove(35);
    tree.levelorder();
}