typedef struct tree{
    int data;
    struct tree * left;
    struct tree * right;
}tree;

void init(tree **root);
tree * createNode(int data);
void rpreorder(tree* root);
void rinorder(tree* root);
void rpostorder(tree* root);
int count(tree* root);
void insert(tree **root, int data);
int search(tree** root, int key);
void delete(tree * root, int elm);
void ipreorder(tree* root);
void iinorder(tree* root);
void ipostorder(tree* root);