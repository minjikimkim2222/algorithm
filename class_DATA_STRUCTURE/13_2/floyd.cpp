#include <iostream>
#include <vector>

using namespace std;

const int number = 4;
const int INF = 100000000;

vector<vector<int>> a = {
    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}
};

void floydWarShall()
{
    vector<vector<int>> d(number, vector<int>(number));

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            d[i][j] = a[i][j];
        }
    }

    for (int k = 0; k < number; k++)
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++){
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++){
            cout << d[i][j] << ' ';

        }
        cout << '\n';
    }
}

int main()
{
    floydWarShall();
    return (0);
}