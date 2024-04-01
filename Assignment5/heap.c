#include "main.h"
#include<stdlib.h>

void init(heap *h, int  size){
    h->arr = (int *)malloc(sizeof(int)*size);
    h->size = size;
    h->length = 0;
};

boolean isEmpty(heap *h)
{
    if(h->length==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

boolean isFull(heap *h){
    if(h->length==h->size){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void insert(heap *h, int elm){
    if(isFull(h)) return;

    int index = h->length++;
    
    
}

void heapify(heap *h,int index);

void peek(heap *h);

int deleteHeaoTop(heap *h);

void heapSort(heap *h);

