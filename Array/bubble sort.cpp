#include <iostream>
using namespace std;
int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);

    bool did_swap = true;
    int to_do = n - 1;

    while (to_do > 0 && did_swap) {
        int index = 0;
        did_swap = false;
        while (index < to_do) {
            if (A[index] > A[index + 1]) {

                int temp = A[index];
                A[index] = A[index + 1];
                A[index + 1] = temp;
                did_swap = true;
            }
            index++;
        }
        to_do--;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
