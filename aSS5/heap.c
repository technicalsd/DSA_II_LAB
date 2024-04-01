#include "heap.h"
#include <stdlib.h>
#include <limits.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void initHeap(heap *h, int size){
    h->size = size;
    h->length = 0;
    h->arr = (int *)malloc(sizeof(int) * size);
}

boolean isHeapEmpty(heap *h){
    if(h->length == 0)return TRUE;
    else return FALSE;
}

boolean isHeapFull(heap *h){
    if(h->length == h->size)return TRUE;
    return FALSE;
}

void insertHeap(heap *h, int val){
    if(isHeapFull(h))return;
    int index = h->length++;
    while(index > 0 && val > h->arr[(index - 1)/2]){
        h->arr[index] = h->arr[(index - 1)/2];
        index = (index - 1)/2;
    }
    h->arr[index] = val;
    return;
}

void heapify(heap *h, int index){
    int leftIndex = 2*index + 1;
    int rightIndex = 2*index + 2;
    if(leftIndex < h->length && h->arr[index] < h->arr[leftIndex]){
        swap(h->arr + leftIndex, h->arr + index);
        heapify(h, leftIndex);
    }
    if(rightIndex < h->length && h->arr[index] < h->arr[rightIndex]){
        swap(h->arr + rightIndex, h->arr + index);
        heapify(h, rightIndex);
    }
    return;


}

int peekHeap(heap *h){
    if(isHeapEmpty(h))return INT_MIN;
    return h->arr[h->length - 1];
}

int deleteHeapTop(heap *h){
    if(isHeapEmpty(h))return INT_MAX;
    swap(h->arr, h->arr+h->length-1);
    int removed = h->arr[--h->length];
    heapify(h, 0);
    return removed;
}

void heapSort(heap *h, int r[]){
    heap newHeap;
    initHeap(&newHeap, h->size);
    for(int i= 0;i<h->length;i++){
        insertHeap(&newHeap, h->arr[i]);
    }
    int i = 0;
    while(!isHeapEmpty(&newHeap)){
        r[i++] = deleteHeapTop(&newHeap);
    }
}

