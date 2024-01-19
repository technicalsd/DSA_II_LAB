#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void init(tree **root) {
    *root = NULL;
}

tree *createNode(int data) {
    tree *newnode = (tree *)malloc(sizeof(tree));

    if (newnode) {
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    } else {
        return NULL;
    }

    return newnode;
}

void rpreorder(tree *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    rpreorder(root->left);
    rpreorder(root->right);
}

void rinorder(tree *root) {
    if (root == NULL) {
        return;
    }
    rinorder(root->left);
    printf("%d ", root->data);
    rinorder(root->right);
}

void rpostorder(tree *root) {
    if (root == NULL) {
        return;
    }
    rpostorder(root->left);
    rpostorder(root->right);
    printf("%d ", root->data);
}

int count(tree *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + count(root->left) + count(root->right);
    }
}

void insert(tree **root, int data) {
    tree *p = *root;
    tree *q = NULL;

    while (p != NULL) {
        q = p;
        if (p->data == data) {
            return;
        } else if (p->data > data) {
            p = p->left;
        } else if (p->data < data) {
            p = p->right;
        }
    }

    if (q == NULL) {
        *root = createNode(data);
    } else if (q->data > data) {
        q->left = createNode(data);
    } else {
        q->right = createNode(data);
    }
}

int search(tree **root, int key){
    tree *p = *root;
    tree *q = NULL;

    while(p!=NULL){
        if(p->data == key){
            return 1;
        }
        else if(key<p->data){
            p = p->left;
        }
        else if(key>p->data){
            p = p->right;
        }
    }
    return 0;
}