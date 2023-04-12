#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100 // define the size of the hash table

typedef struct {
    char* key;
    int value;
} hash_node;

hash_node* hash_table[TABLE_SIZE];

// hash function to map a string key to an index in the hash table
int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// function to insert a key-value pair into the hash table
void insert(char* key, int value) {
    int index = hash(key);
    hash_node* new_node = (hash_node*) malloc(sizeof(hash_node));
    new_node->key = key;
    new_node->value = value;
    hash_table[index] = new_node;
}

// function to retrieve a value from the hash table given its key
int get(char* key) {
    int index = hash(key);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->key, key) == 0) {
        return hash_table[index]->value;
    }
    return -1;
}

int main() {
    insert("apple", 5);
    insert("banana", 10);
    printf("%d\n", get("apple")); // prints 5
    printf("%d\n", get("banana")); // prints 10
    printf("%d\n", get("cherry")); // prints -1
    return 0;
}
