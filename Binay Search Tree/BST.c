#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

// function to create a new node with the given value
node* create_node(int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// function to insert a new node with the given value into the tree
node* insert(node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// function to delete the node with the given value from the tree
node* delete(node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}

// function to search for a node with the given value in the tree
node* search(node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// function to perform an in-order traversal of the tree and print each node's value
void inorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

int main() {
    node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("In-order traversal: ");
    inorder_traversal(root);
    printf("\n");
    delete(root, 20);
    delete(root, 30);
    delete(root, 50);
    printf("In-order traversal after deletion: ");
    inorder_traversal(root);
    printf("\n");
    node* search_result = search(root, 60);
    if (search_result != NULL) {
        printf("Node found: %d\n", search_result->value);
    } else {
        printf("Node not found\n");
    }
    return 0;
}
