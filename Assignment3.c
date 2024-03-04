#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Define a structure for the binary tree node
typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new binary tree node
TreeNode* createNode(char val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to get the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}




// Function to build the expression tree recursively
TreeNode* buildTree(char* s, int start, int end) {
    if (start > end)
        return NULL;

    int minPrecedence = INT_MAX;
    int minPrecedenceIndex = -1;
    int level = 0;

    for (int i = start; i <= end; ++i) {
        if (s[i]==' ')
            continue;
        else if (s[i] == '(')
            level++;
        else if (s[i] == ')')
            level--;
        else if (level == 0 && isOperator(s[i])) {
            int currentPrecedence = precedence(s[i]);
            if (currentPrecedence <= minPrecedence) {
                minPrecedence = currentPrecedence;
                minPrecedenceIndex = i;
            }
        }
    }

    if (minPrecedenceIndex == -1) {
        // If no operator found, treat the expression as an operand
        // Remove surrounding parentheses if present
        if (s[start] == '(' && s[end] == ')') {
            return buildTree(s, start + 1, end - 1);
        } else {
            // Create a new node for operand
            TreeNode* operandNode = createNode(s[start]);
            return operandNode;
        }
    }

    // Create a new node for the operator
    TreeNode* root = createNode(s[minPrecedenceIndex]);

    // Recursively build left and right subtrees
    root->left = buildTree(s, start, minPrecedenceIndex - 1);
    root->right = buildTree(s, minPrecedenceIndex + 1, end);

    return root;
}

void Inorder(TreeNode* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%c ", root->val);
        Inorder(root->right);
    }
}

int main() {
    char infix_expression[] = "((a+b)*c)-(d/e)";
    int n = strlen(infix_expression);
    
    TreeNode* root = buildTree(infix_expression, 0, n - 1);

    printf("Infix traversal of the expression tree: ");
    Inorder(root);
    printf("\n");

    return 0;
}