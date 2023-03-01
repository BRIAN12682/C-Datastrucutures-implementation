#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the priority queue

// Define a struct to represent the priority queue
typedef struct {
    int data[MAX_SIZE]; // Array to store the elements of the queue
    int size; // Number of elements currently in the queue
} PriorityQueue;

// Function to initialize a priority queue
void initialize(PriorityQueue *q) {
    q->size = 0; // Set the size to zero
}

// Function to insert an element into the priority queue
void enqueue(PriorityQueue *q, int value) {
    // Check if the queue is already full
    if (q->size == MAX_SIZE) {
        printf("Queue overflow\n"); // Print an error message and return if so
        return;
    }

    // Find the correct position to insert the new element
    int i = q->size++; // Set i to the end of the array and increment the size
    while (i > 0 && value > q->data[(i - 1) / 2]) { // While the parent of i is less than the new value
        q->data[i] = q->data[(i - 1) / 2]; // Move the parent down to the current position
        i = (i - 1) / 2; // Move i up to the parent's previous position
    }
    q->data[i] = value; // Insert the new value into the correct position
}

// Function to remove the highest-priority element from the priority queue
int dequeue(PriorityQueue *q) {
    // Check if the queue is empty
    if (q->size == 0) {
        printf("Queue underflow\n"); // Print an error message and return -1 if so
        return -1;
    }

    // Remove the root element (highest priority) from the queue
    int root = q->data[0];
    int last = q->data[--q->size]; // Get the last element in the array and decrement the size

    // Restore the heap property by moving the last element down to the root position
    int i = 0; // Start at the root
    while (2 * i + 1 < q->size) { // While the left child of i is still within the array
        int child = 2 * i + 1; // Set child to the left child of i
        if (child + 1 < q->size && q->data[child + 1] > q->data[child]) { // If the right child is larger than the left child
            child++; // Set child to the right child
        }
        if (last >= q->data[child]) { // If the last element is larger than or equal to its largest child
            break; // We've found the correct position for the last element, so we can stop
        }
        q->data[i] = q->data[child]; // Move the largest child up to the current position
        i = child; // Move i down to the child's position
    }
    q->data[i] = last; // Insert the last element into the correct position

    return root; // Return the root element that was removed
}

// Main function to test the priority queue
int main() {
    PriorityQueue q;
    initialize(&q);

    enqueue(&q, 5);
    enqueue(&q, 3);
    enqueue(&q, 8);
    enqueue(&q, 2);

    printf("%d\n", dequeue(&q)); // 8
    printf("%d\n", dequeue(&q)); //9
}