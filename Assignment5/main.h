#ifndef HEAP H

typedef enum boolean {TRUE, FALSE} boolean

typedef struct heap{
    int *arr;
    int size;
    int length;
}heap;


void init(heap *h, int size);

boolean isFull(heap *h);
boolean isEmpty(heap *h);

void insert(heap *h, int elm);

void heapify(heap *h,int index);

void peek(heap *h);

int deleteHeaoTop(heap *h);

void heapSort(heap *h);


#endif