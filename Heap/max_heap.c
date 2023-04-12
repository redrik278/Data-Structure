#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int* arr;
    int size;
} heap;

// function to initialize a new heap with the given maximum size
heap* create_heap(int max_size) {
    heap* new_heap = (heap*) malloc(sizeof(heap));
    new_heap->arr = (int*) malloc(sizeof(int) * max_size);
    new_heap->size = 0;
    return new_heap;
}

// function to swap two elements in an array
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// function to insert a new element into the heap
void insert(heap* h, int value) {
    if (h->size >= MAX_HEAP_SIZE) {
        printf("Heap overflow\n");
        return;
    }
    h->arr[h->size] = value;
    int i = h->size;
    while (i > 0 && h->arr[i] > h->arr[(i - 1) / 2]) {
        swap(h->arr, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
    h->size++;
}

// function to delete the maximum element from the heap
void delete_max(heap* h) {
    if (h->size == 0) {
        printf("Heap underflow\n");
        return;
    }
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    int i = 0;
    while (i * 2 + 1 < h->size) {
        int max_child = i * 2 + 1;
        if (i * 2 + 2 < h->size && h->arr[i * 2 + 2] > h->arr[max_child]) {
            max_child = i * 2 + 2;
        }
        if (h->arr[i] < h->arr[max_child]) {
            swap(h->arr, i, max_child);
            i = max_child;
        } else {
            break;
        }
    }
}

// function to build a heap from an array of elements
void build_heap(heap* h, int* arr, int size) {
    if (size > MAX_HEAP_SIZE) {
        printf("Heap overflow\n");
        return;
    }
    h->size = size;
    for (int i = 0; i < size; i++) {
        h->arr[i] = arr[i];
    }
    for (int i = (size - 1) / 2; i >= 0; i--) {
        int j = i;
        while (j * 2 + 1 < size) {
            int max_child = j * 2 + 1;
            if (j * 2 + 2 < size && h->arr[j * 2 + 2] > h->arr[max_child]) {
                max_child = j * 2 + 2;
            }
            if (h->arr[j] < h->arr[max_child]) {
                swap(h->arr, j, max_child);
                j = max_child;
            } else {
                break;
            }
        }
    }
}

int main() {
    heap* h = create_heap(MAX_HEAP_SIZE);
    insert(h, 10);
    insert(h, 20);
    insert(h, 30);
    insert(h, 40);
    insert(h, 50);
    insert(h, 60);
    printf("Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
    delete_max(h);
    printf("Heap after delete: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
    int arr[] = {50, 20, 30, 10, 40, 60};
    heap* h2 = create_heap(MAX_HEAP_SIZE);
    build_heap(h2, arr, 6);
    printf("Heap from array: ");
    for (int i = 0; i < h2->size; i++) {
        printf("%d ", h2->arr[i]);
    }
    printf("\n");
    return 0;
}