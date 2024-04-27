#include <iostream>
#include <vector>
using namespace std;

// Function to move values to the left or right side of the array in relation to k
void partitionRecursive(vector<int>& A, int start, int end, int k) {
    // Stop if the subarray is too small
    if (start >= end) return;

    // Use the last element
    int pivot = A[end];
    int i = start - 1; // Initialize the position

    // Organize elements
    for (int j = start; j < end; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    // Place the pivot in its correct position
    swap(A[i + 1], A[end]);

    // Recursively partition the left or right side of the array in relation to k
    if (pivot > k) {
        partitionRecursive(A, start, i, k);
    } else {
        partitionRecursive(A, i + 2, end, k);
    }
}

// Function to start recursive partitioning process
void rearrange(vector<int>& A, int k) {
    partitionRecursive(A, 0, A.size() - 1, k);
}

int main() {
    vector<int> A = {10, 1, 14, 3, 16, 7, 20, 5, 12, 8, 6, 11, 4, 13, 9, 15, 2, 18, 19, 17};
    int k = 10;

    cout << "pre partitioning: \n"; // Display the list before sorting
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    rearrange(A, k);  // Rearrange the array around k
    
    cout << "post partitioning: \n"; // Display the list after sorting
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}