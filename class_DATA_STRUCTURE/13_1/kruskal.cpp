#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VERTICES 100

using namespace std;
class Edge{

    public:
        int node[2];
        int weight;
        
        Edge(int a, int b, int weight){
            this -> node[0] = a;
            this -> node[1] = b;
            this -> weight = weight;
        }

        bool operator<(Edge& edge){
            return this -> weight < edge.weight;
        }
};

class VertexSets{

    int parent[MAX_VERTICES];
    int size;
    public:
        VertexSets(int nSets)
        {
            size = nSets;
            for (int i = 0; i < nSets; i++)
                parent[i] = -1;
        }

        bool IsRoot(int i) { return parent[i] < 0;}

        int findSet(int vertex){
            int id = vertex;
            while (!IsRoot(id)) id = parent[id];
            return (id);
        }

        void unionSets(int s1, int s2){
            parent[s1] = s2;
            size--;
        }
};

class Kruskal{

    public:
        VertexSets vs;
        std::vector<Edge> edges;

        Kruskal(int N) : vs(N) {}

        void insertEdge(int nodeA, int nodeB, int weight){
            edges.push_back(Edge(nodeA, nodeB, weight));
        }

        void execute()
        {
            sort(edges.begin(), edges.end());

            int totalWeight = 0;
            for (auto edge : edges){
                int set1 = vs.findSet(edge.node[0]);
                int set2 = vs.findSet(edge.node[1]);

                if (set1 != set2){
                    totalWeight += edge.weight;
                    vs.unionSets(set1, set2);
                    cout << "Added edge " << edge.node[0] << " - " << edge.node[1]
                        << " with weight " << edge.weight << '\n';
                }
            }
            cout << "Total Weight: " << totalWeight << '\n';
        }


};

int main()
{
    Kruskal k(7);

    k.insertEdge(0,1,9);
    k.insertEdge(0,2,10);
    k.insertEdge(1,3,10);
    k.insertEdge(1,4,5);
    k.insertEdge(2,4,7);
    k.insertEdge(2,5,2);
    k.insertEdge(3,6,4);
    k.insertEdge(4,6,7);
    k.insertEdge(5,6,6);
    k.execute();

    return (0);
}