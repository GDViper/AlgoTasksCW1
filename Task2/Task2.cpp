#include <iostream>
using namespace std;

// Structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Class to manage the doubly linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Initialize an empty doubly linked list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to add a node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value); // Create a node
        if (head == nullptr) {
            // If the list is empty set both head and tail to the new node
            head = newNode;
            tail = newNode;
            return;
        }
        // Link the new node to the current tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Function to print all elements
    void printList() {
        Node* temp = head;  // Start from the head of the list
        while (temp != nullptr) {
            cout << temp->data << " ";  // Output the data of each node
            temp = temp->next;
        }
        cout << endl;
    }
};

// Function to find the last node
Node* getLastNode(Node* node) {
    while (node->next != nullptr)
        node = node->next;
    return node; // Return the last node
}

// Function to partition the list
Node* partition(Node* low, Node* high) {
    int pivot = high->data;  // The pivot is the data of the high node
    Node* i = low->prev;     // Start from the node before low

    // Iterate through the list
    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            // Find the correct position for the node
            i = (i == nullptr) ? low : i->next;
            swap(i->data, j->data);  // Swap the data of node i and j
        }
    }
    // Place pivot correctly
    i = (i == nullptr) ? low : i->next;
    swap(i->data, high->data);
    return i; // Return the partitioning point
}

// Function to implement quick sort
void quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* p = partition(low, high);  // Partition the list and get the pivot location
        quickSort(low, p->prev);         // Sort the left sublist
        quickSort(p->next, high);        // Sort the right sublist
    }
}

int main() {
    DoublyLinkedList dll;  // Create a doubly linked list
    
    // Append the values to the list
    dll.append(10);
    dll.append(30);
    dll.append(3);
    dll.append(4);
    dll.append(20);
    dll.append(5);

    cout << "Original list: \n";
    dll.printList();  // Display the list before sorting

    Node* last = getLastNode(dll.head);  // Get the last node of the list
    quickSort(dll.head, last);  // Call the function to apply the quick sort algorithm

    cout << "Sorted list: ";
    dll.printList();  // Display the list after sorting

    return 0;
}