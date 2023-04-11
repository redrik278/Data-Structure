#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = top;
    if (top != NULL) {
        top->prev = newNode;
    }
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    free(temp);
    return value;
}

int peek() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

void printStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    printStack();  // Output: Stack: 3 2 1

    int popped = pop();
    printf("Popped value: %d\n", popped);  // Output: Popped value: 3
    printStack();  // Output: Stack: 2 1

    int peeked = peek();
    printf("Peeked value: %d\n", peeked);  // Output: Peeked value: 2
    printStack();  // Output: Stack: 2 1

    push(4);
    printStack();  // Output: Stack: 4 2 1

    return 0;
}
