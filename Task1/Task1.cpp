#include <iostream>
#include <unordered_set>  // Include for unordered_set
using namespace std;

// Function to remove duplicate characters
void removeDuplicates(char arr[], int n) {
    unordered_set<char> seen;  // Unordered set initialization
    int j = 0; // Pointer initialization

    // Iterate over each character in the input array
    for (int i = 0; i < n; ++i) {
        // Check if the current character is not in the unordered_set
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);  // Add unseen character to the unordered  set
            arr[j++] = arr[i];  // Place the unique character in the array at index j then increment j
        }
    }

    // Null-terminate the array
    arr[j] = '\0';
}

int main() {
    char arr[] = "2165134161651418191574218746452476531";  // Pre duplicate removal array
    int n = sizeof(arr) - 1; // Calculate the length of the array

    // Display the array before removing duplicates
    cout << "Pre duplicate removal\n" << arr << endl;

    // Call the function to remove duplicates
    removeDuplicates(arr, n);

    // Display the array after removing duplicates
    cout << "Post duplicates removal:\n" << arr << endl;
    return 0;
}