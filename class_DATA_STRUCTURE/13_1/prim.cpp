#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VERTICES 100

class Edge{
    public:
        int node;
        int weight;

        Edge(int node, int weight){
            this -> node = node;
            this -> weight = weight;
        }
        bool operator<(const Edge& edge) const{
            return this -> weight > edge.weight;
        }
};

class Prim{

    public:
        int num_vertex;
        std::vector<Edge> graph[MAX_VERTICES];

        Prim(int num_vertex){
            this -> num_vertex = num_vertex;
        }

        void addEdge(int nodeA, int nodeB, int weight){
            graph[nodeA].push_back(Edge(nodeB, weight));
            graph[nodeB].push_back(Edge(nodeA, weight));
        }

        void execute(int start){
            std::vector<bool> selected(num_vertex, false);
            std::priority_queue<Edge> Q;
            Q.push(Edge(start, 0));

            int totalWeight = 0;
            while (!Q.empty()){
                Edge cur = Q.top();
                Q.pop();
                if (selected[cur.node]) continue;

                selected[cur.node] = true;

                totalWeight += cur.weight;

                for (Edge next : graph[cur.node]){
                    if (!selected[next.node]) Q.push(next);
                }
            }

            std::cout << "Total weight: "<< totalWeight << '\n';
        }
};


int main(){
    Prim p(7);

    p.insertEdge(0,1,9);
    p.insertEdge(0,2,10);
    p.insertEdge(1,3,10);
    p.insertEdge(1,4,5);
    p.insertEdge(2,4,7);
    p.insertEdge(2,5,2);
    p.insertEdge(3,6,4);
    p.insertEdge(4,6,7);
    p.insertEdge(5,6,6);
    p.execute();

    return (0);
}