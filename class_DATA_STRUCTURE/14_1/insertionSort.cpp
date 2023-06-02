#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A)
{
    int n = A.size();

    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;

    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    insertionSort(arr);
    cout << "Sorted array using insertion Sort : \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << '\n';
    return (0);
}