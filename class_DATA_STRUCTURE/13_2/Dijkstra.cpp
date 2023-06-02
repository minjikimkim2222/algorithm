#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int number = 6;
int start = 1;
bool visited[6];
int dist[6];

vector<pair<int, int>> a[7];

void dijkstra(int start)
{
    dist[start] = 0;
    for (int i = 0; i < number; i++)
    {
        int current = -1;
        int minDist = INF;
        for (int j = 1; j <= number; j++)
        {
            if (!visited[i] && minDist > dist[j]){
                minDist = dist[j];
                current = j;
            }
        }
        visited[current] = true;
        for (int j = 0; j < a[current].size(); j++)
        {
            int near= a[current][j].first;
            int nearDist = a[current][j].second;

            if (dist[near] > dist[current] + nearDist){
                dist[near] = dist[current] + nearDist;
            }
        }
    }
}

int main(void)
{
    for (int i = 1; i < number; i++){
        dist[i] = INF;
    }
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(3,5));
    a[1].push_back(make_pair(4,1));
    a[2].push_back(make_pair(1,2));
    a[2].push_back(make_pair(3,3));
    a[2].push_back(make_pair(4,2));
    a[3].push_back(make_pair(1,5));
    a[3].push_back(make_pair(2,3));
    a[3].push_back(make_pair(4,3));
    a[3].push_back(make_pair(5,1));
    a[3].push_back(make_pair(6,5));
    a[4].push_back(make_pair(1,1));
    a[4].push_back(make_pair(2,2));
    a[4].push_back(make_pair(3,3));
    a[4].push_back(make_pair(5,1));
    a[5].push_back(make_pair(3,1));
    a[5].push_back(make_pair(4,1));
    a[5].push_back(make_pair(6,2));
    a[6].push_back(make_pair(3,5));
    a[6].push_back(make_pair(5,2));

    dijkstra(start);
    for (int i = 1; i<=number; i++)
    {
        if (dist[i] == INF)
            cout << "INF ";
        else 
            cout << dist[i] << " ";
    }


    return (0);
}