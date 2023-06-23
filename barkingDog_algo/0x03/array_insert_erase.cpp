#include <iostream>

using namespace std;

void insert_Arr(int idx, int data, int arr[], int& len)
{
    for (int i = len; i > idx ; i--)
        arr[i] = arr[i-1];
    arr[idx] = data;
    len++;
}

void erase_Arr(int idx, int arr[], int& len)
{
    for(int i = idx; i < len - 1; i++)
        arr[i] = arr[i+1];
    len--;
}

void print_Arr(int arr[], int& len){
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout <<"\n\n";
}

int main(void)
{
    int arr[10] = {10, 20, 30};
    int len = 3;
    insert_Arr(3, 40, arr, len); // 10 20 30 40
    print_Arr(arr, len);
    erase_Arr(1, arr, len); // 10 30 40
    print_Arr(arr, len);

}