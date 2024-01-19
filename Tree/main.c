#include<stdio.h>
#include "tree.h"


int main(){
    tree* root;
    init(&root);

    int numbers[] = {5, 3, 8, 2, 4, 6, 9, 1, 7, 10};
    int i, n = sizeof(numbers) / sizeof(numbers[0]);

    for (i = 0; i < n; i++) {
        insert(&root, numbers[i]);
    }

    rpreorder(root);
    printf("\n");
    rinorder(root);
    printf("\n");
    rpostorder(root);

    if(search(&root,2)){
    printf("Element found, Search successful");
    }
    else{
        printf("Element does not found, Search Unsucessful");
    }

    return 0;
}
