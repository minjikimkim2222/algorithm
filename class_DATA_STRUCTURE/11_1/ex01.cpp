#include <iostream>

using namespace std;

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

 class BinaryTree
        {
            BinaryNode* root;
            
            public:
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
            private :
                void    display(BinaryNode* node, int depth){
                    if (node == NULL)
                        return ;
                    else{
                        for (int i = 0; i < depth; i++)
                            cout << " ";
                        cout << "- " << static_cast<char>(node -> getData()) << endl;

                        display(node -> getLeft(), depth + 1);
                        display(node -> getRight(), depth + 1);
                    }
                }



        };

int main()
{
    BinaryTree tree;

    BinaryNode* d = new BinaryNode('D', NULL, NULL);
    BinaryNode* e = new BinaryNode('E', NULL, NULL);
    BinaryNode* b= new BinaryNode('B', d, e);
    BinaryNode* f= new BinaryNode('F', NULL, NULL);
    BinaryNode* c= new BinaryNode('C', f, NULL);
    BinaryNode* a= new BinaryNode('A', b, c);
    
    tree.setRoot(a);
    tree.display();

    return (0);
}