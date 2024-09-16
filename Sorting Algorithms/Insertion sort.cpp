#include <iostream>
using namespace std;

int main()
{
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;

        // Shift elements to the right until the correct position is found for the key
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key; // Place the key in the correct position
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
