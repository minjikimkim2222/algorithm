#include <iostream>
#include <fstream>
#define MAX_VTXS 256

using namespace std;

class Node
{
    protected:
        int id;
        Node* link;
    public:
        Node(int i, Node*l = NULL): id(i), link(l) { }
        ~Node(void)
        {
            if (link != NULL)
                delete link;
        }

        int getId() {return (id);}
        Node* getLink() {return link;}
        void setLink(Node* l) { link = l;}
      
};

class AdjListGraph
{
        int size;
        char vertices[MAX_VTXS];
        Node* adj[MAX_VTXS];

    public:
        AdjListGraph(void) : size(0) { }
        ~AdjListGraph() { reset();}

       void reset(void)
       {
        for (int i =0; i < size; i++)
            if (adj != NULL) delete adj[i];
        size = 0;
       }
       bool isEmpty() {return (size == 0);}
       bool isFull() {return (size >= MAX_VTXS);}
       char getVertex(int i) {return vertices[i];}

       void insertVertex(char val)
       {
        if (!isFull())
        {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else
            cout << "Error : 그래프 정점 개수 초과" << '\n';
       }

       void insertEdge(int u, int v)
       {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
       }

       void display()
       {
        cout << size << '\n';
        for (int i = 0; i < size; i++){
            cout << getVertex(i) << "  ";
            for (Node *v = adj[i]; v != NULL; v = v -> getLink())
                cout << "   " << getVertex(v -> getId());
            cout << "\n";
        }
       }

       void load(const string& filename)
       {
        ifstream file(filename);

        int n;
        file >> n;
        for (int i = 0; i < n; i++)
        {
            char str[80];
            int val;
            file >> str;

            insertVertex(str[0]);
            for (int j = 0; j < n; j++){
                file >> val;
                if (val != 0)
                    insertEdge(i,j);
            }
        }
       }
};

int main(void)
{
    AdjListGraph g;

    for (int i = 0; i < 4; i++)
        g.insertVertex('A' + i);
        
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    g.insertEdge(1,3);
    g.insertEdge(2,3);

    cout << "인접 리스트로 표현한 그래프" << '\n';
    g.display();
}