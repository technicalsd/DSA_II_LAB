#include "heap.h"
#include <stdio.h>

void print(int a[], int size){
    while(size--){
        printf("%d ", a[size]);
    }
}
int main()
{
    heap h;
    initHeap(&h, 10);
    insertHeap(&h, 19);
    insertHeap(&h, 12);
    insertHeap(&h, 76);
    insertHeap(&h, 41);
    insertHeap(&h, 25);
    insertHeap(&h, 15);
    int sorted[6];
    heapSort(&h, sorted);
    print(sorted, 6);
    return 0;
}