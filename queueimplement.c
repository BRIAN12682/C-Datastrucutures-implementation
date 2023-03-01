#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

int queue[MAX_SIZE]; // Declare an array to hold the queue elements
int front = 0, rear = -1; // Initialize the front and rear of the queue

// Function to add an item to the rear of the queue
void enqueue(int item) {
    // Check if the queue is already full
    if (rear >= MAX_SIZE - 1) {
        printf("Queue overflow\n"); // Print an error message
        return; // Return without adding the item to the queue
    }
    queue[++rear] = item; // Increment the rear of the queue and add the item
}

// Function to remove and return the item from the front of the queue
int dequeue() {
    // Check if the queue is empty
    if (front > rear) {
        printf("Queue underflow\n"); // Print an error message
        exit(1); // Exit the program with an error code
    }
    return queue[front++]; // Return the front element and increment the front of the queue
}

// Main function to test the queue implementation
int main() {
    enqueue(10); // Add 10 to the rear of the queue
    enqueue(20); // Add 20 to the rear of the queue
    enqueue(30); // Add 30 to the rear of the queue

    printf("%d\n", dequeue()); // Remove and print the front element (10)
    printf("%d\n", dequeue()); // Remove and print the front element (20)
    printf("%d\n", dequeue()); // Remove and print the front element (30)
    printf("%d\n", dequeue()); // Attempt to remove an element from an empty queue (will print "Queue underflow" and exit with an error)

    return 0; // Exit the program with a success code
}
