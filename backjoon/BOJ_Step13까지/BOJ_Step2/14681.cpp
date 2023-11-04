#include <iostream>

using namespace std;


int main(void)
{
    int x,y;
    int ret = 0;
    cin >> x >> y;

    if (x > 0)
    {
        if (y > 0)
            ret = 1;
        else
            ret = 4;
    }
    else if (x < 0)
    {
        if (y > 0)
            ret = 2;
        else
            ret = 3;
    }
    cout << ret;
    return (0);
}