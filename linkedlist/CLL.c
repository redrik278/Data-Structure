// C code to perform circular linked list operations

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* addToEmpty(struct Node* head, int data) {
  if (head != NULL) return head;

  // allocate memory to the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // assign data to the new node
  newNode->data = data;

  // assign head to newNode
  head = newNode;

  // create link to iteself
  head->next = head;

  return head;
}

// add node to the front
struct Node* addFront(struct Node* head, int data) {
  // check if the list is empty
  if (head == NULL) return addToEmpty(head, data);

  // allocate memory to the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // add data to the node
  newNode->data = data;

  // store the address of the current first node in the newNode
  newNode->next = head->next;

  // make newNode as head
  head->next = newNode;

  return head;
}

// add node to the end
struct Node* addEnd(struct Node* head, int data) {
  // check if the node is empty
  if (head == NULL) return addToEmpty(head, data);

  // allocate memory to the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // add data to the node
  newNode->data = data;

  // store the address of the head node to next of newNode
  newNode->next = head->next;

  // point the current head node to the newNode
  head->next = newNode;

  // make newNode as the head node
  head = newNode;

  return head;
}

// insert node after a specific node
struct Node* addAfter(struct Node* head, int data, int item) {
  // check if the list is empty
  if (head == NULL) return NULL;

  struct Node *newNode, *p;

  p = head->next;
  do {
  // if the item is found, place newNode after it
  if (p->data == item) {
    // allocate memory to the new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    // add data to the node
    newNode->data = data;

    // make the next of the current node as the next of newNode
    newNode->next = p->next;

    // put newNode to the next of p
    p->next = newNode;

    // if p is the head node, make newNode as the head node
    if (p == head) head = newNode;
    return head;
  }

  p = p->next;
  } while (p != head->next);

  printf("\nThe given node is not present in the list");
  return head;
}

// delete a node
void deleteNode(struct Node** head, int key) {
  // if linked list is empty
  if (*head == NULL) return;

  // if the list contains only a single node
  if ((*head)->data == key && (*head)->next == *head) {
  free(*head);
  *head = NULL;
  return;
  }

  struct Node *temp = *head, *d;

  // if head is to be deleted
  if ((*head)->data == key) {
  // find the node before the head node
  while (temp->next != *head) temp = temp->next;

  // point temp node to the next of head i.e. first node
  temp->next = (*head)->next;
  free(*head);
  *head = temp->next;
  }

  // travel to the node to be deleted
  while (temp->next != *head && temp->next->data != key) {
  temp = temp->next;
  }

  // if node to be deleted was found
  if (temp->next->data == key) {
  d = temp->next;
  temp->next = d->next;
  free(d);
  }
}


void traverse(struct Node* head) {
  struct Node* p;

  if (head == NULL) {
  printf("The list is empty");
  return;
  }

  p = head->next;

  do {
  printf("%d ", p->data);
  p = p->next;

  } while (p != head->next);
}

int main() {
  struct Node* head = NULL;

  head = addToEmpty(head, 6);
  head = addEnd(head, 8);
  head = addFront(head, 2);

  head = addAfter(head, 10, 2);

  traverse(head);

  deleteNode(&head, 8);

  printf("\n");

  traverse(head);

  return 0;
}