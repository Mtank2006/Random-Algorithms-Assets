#include <stdio.h>
#include <stdlib.h>
typedef struct AVL_Tree {   
    int key;
    struct AVL_Tree* left;
    struct AVL_Tree* right;
    int height;
}Node;
Node* create_node(int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = val;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int getHeight(Node* node) {
    return (node == NULL) ? 0 : node->height;
}
int getBalance(Node* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}
Node* insert(Node* node, int key) {
    if (node == NULL)
        return create_node(key);
    if (key < node->key) 
        node->left = insert(node->left, key);
    else if (key > node->key) 
        node->right = insert(node->right, key);
    else 
        return node; // after > and < only dup will be left which is not allowed
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) 
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder_bt(Node* root) {
    if (root == NULL)       return;
    printf("%d, ",root->key);          preOrder_bt(root->left);         preOrder_bt(root->right);
}
void inOrder_bt(Node* root) {
    if (root == NULL)       return;
    inOrder_bt(root->left);      printf("%d, ",root->key);              inOrder_bt(root->right);
}
void postOrder_bt(Node* root) {
    if (root == NULL)       return;
    postOrder_bt(root->left);    postOrder_bt(root->right);       printf("%d, ",root->key);
}
int main() {
    Node* avl = NULL;
    avl = insert(avl, 50);
    avl = insert(avl, 30);
    avl = insert(avl, 70);
    avl = insert(avl, 20);
    avl = insert(avl, 40);
    avl = insert(avl, 60);
    avl = insert(avl, 80);
    avl = insert(avl, 10);
    avl = insert(avl, 35);
    avl = insert(avl, 65);
    preOrder_bt(avl);
}