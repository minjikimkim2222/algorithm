#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int>& A)
{
    int n = A.size();

    for (int i = 0; i < n - 1; i++)
    {
        int least = i;
        for (int j = i+1; j < n; j++)
           if (A[j] < A[least])
                least = j;
        swap(A[least], A[i]);
    }
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int main(void)
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    selectionSort(arr);
    cout << "Sorted array using Selection Sort : \n";
    printArray(arr);
    return (0);
}