#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

int peek() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void printStack() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
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
