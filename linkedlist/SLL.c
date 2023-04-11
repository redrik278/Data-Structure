#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create an empty list
struct Node* createList() {
    return NULL;
}

// insert a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// insert a new node at any position in the list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        // insert at the beginning
        newNode->next = head;
        return newNode;
    }

    struct Node* prev = head;
    struct Node* curr = head->next;
    int pos = 2;
    while (curr != NULL && pos < position) {
        prev = curr;
        curr = curr->next;
        pos++;
    }

    if (pos == position) {
        // insert at the specified position
        prev->next = newNode;
        newNode->next = curr;
    } else {
        printf("Position out of range\n");
    }

    return head;
}

// delete the first occurrence of a node with a given value
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        // list is empty
        return NULL;
    }

    if (head->data == data) {
        // the node to be deleted is the first node
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = head;
    struct Node* curr = head->next;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        // found the node to be deleted
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Node not found\n");
    }

    return head;
}

// search for a node with a given value and return its position
int searchNode(struct Node* head, int data) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == data) {
            return pos;
        }
        head = head->next;
        pos++;
    }
    return -1;
}

// print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createList();

    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);

    head = insertAtPosition(head, 4, 4);
    head = insertAtPosition(head, 5, 2);

    printf("List: ");
    printList(head);

    head = deleteNode(head, 3);

    printf("List after deleting 3: ");
    printList(head);

    int pos = searchNode(head, 5);
        if (pos != -1) {
        printf("5 is found at position %d\n", pos);
    } else {
        printf("5 not found in the list\n");
    }

    return 0;
}
