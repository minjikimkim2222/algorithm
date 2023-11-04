#include <iostream>

using namespace std;

int main(void)
{
   int X; // 영수증 총 금액
   int n; // 물건 종류 개수
   int a,b; // 각각 물건의 가격, 개수
   int comparePrice = 0; 

   cin >> X;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
        cin >> a >> b;
        comparePrice += a*b;
   }

   if (X == comparePrice){
        cout << "Yes";
    }
   else{
        cout << "No";
   }
   return (0);
}