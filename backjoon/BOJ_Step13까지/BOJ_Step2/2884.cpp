#include <iostream>

using namespace std;

int main(void)
{
     //10 10 -> -45 -> m < 0 , h-- -> 60 - 나머지(45-10) -> 9 25
     // 23 40
     // 0 30
     // 10 50 -> -45 -> 10 5
    int h,m;
    cin >> h >> m;

    if (m - 45 < 0){
        if (h == 0)
            h = 23;
        else 
            h--;
        m = 60 - (45 - m);
        cout << h << ' ' << m;
    }
    else
    {
        m = m - 45;
        cout << h << ' ' << m;
    }


}