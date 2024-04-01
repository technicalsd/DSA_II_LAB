#ifndef HEAP_H
#define HEAP_H
typedef enum boolean {FALSE, TRUE} boolean;
typedef struct heap{
    int *arr;
    int size;
    int length;
} heap;

void swap(int *a, int *b);
void initHeap(heap *h, int size);

boolean isHeapEmpty(heap *h);

boolean isHeapFull(heap *h);

void insertHeap(heap *h, int val);

void heapify(heap *h, int index);

int peekHeap(heap *h);

int deleteHeapTop(heap *h);

void heapSort(heap *h, int[]);
#endif