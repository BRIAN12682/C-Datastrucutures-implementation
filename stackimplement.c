#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE]; // Declare an array to hold the stack elements
int top = -1; // Initialize the top of the stack to -1, indicating an empty stack

// Function to add an item to the top of the stack
void push(int item) {
    // Check if the stack is already full
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n"); // Print an error message
        return; // Return without adding the item to the stack
    }
    stack[++top] = item; // Increment the top of the stack and add the item
}

// Function to remove and return the item from the top of the stack
int pop() {
    // Check if the stack is empty
    if (top < 0) {
        printf("Stack underflow\n"); // Print an error message
        exit(1); // Exit the program with an error code
    }
    return stack[top--]; // Return the top element and decrement the top of the stack
}

// Main function to test the stack implementation
int main() {
    push(10); // Push 10 onto the stack
    push(20); // Push 20 onto the stack
    push(30); // Push 30 onto the stack


    printf("%d\n", pop()); // Pop and print the top element (30)
    printf("%d\n", pop()); // Pop and print the top element (20)
    printf("%d\n", pop()); // Pop and print the top element (10)
    printf("%d\n", pop()); // Attempt to pop an element from an empty stack (will print "Stack underflow" and exit with an error)

    return 0; // Exit the program with a success code
}
