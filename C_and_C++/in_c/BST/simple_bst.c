#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct simple_bst
{
    int data;
    struct simple_bst * left , * right;
}simple_bst;
simple_bst* create_root(int data) {
    simple_bst* new_block = (simple_bst*)malloc(sizeof(simple_bst));
    new_block->data = data;
    new_block->left = NULL;
    new_block->right = NULL;
    return new_block;
}
simple_bst* insert_simple_bst(simple_bst* root,int data) {
    if (root == NULL) {
        return create_root(data);
    }
    if (data < root->data)
        root->left = insert_simple_bst(root->left, data);
    else
        root->right = insert_simple_bst(root->right, data);

    return root;
}
bool search_bst(simple_bst* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (root->data > key) return search_bst(root->left,key);
    return search_bst(root->right,key);
}
simple_bst* getSuccessor(simple_bst* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL) 
    {
        curr = curr->left;
    }
    return curr;   
}
simple_bst* delNode(simple_bst* root, int value) {
    if (root == NULL) return root;
    if (root->data > value) {
        root->left = delNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = delNode(root->right, value);
    }
    else {
        if (root->left == NULL) {
            simple_bst* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            simple_bst* temp = root->left;
            free(root);
            return temp;
        }

        simple_bst* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}
void preOrder_simple_bst(simple_bst* root) {
    if (root == NULL)       return;
    printf("%d, ",root->data);          preOrder_simple_bst(root->left);         preOrder_simple_bst(root->right);
}
void inOrder_simple_bst(simple_bst* root) {
    if (root == NULL)       return;
    inOrder_simple_bst(root->left);      printf("%d, ",root->data);              inOrder_simple_bst(root->right);
}
void postOrder_simple_bst(simple_bst* root) {
    if (root == NULL)       return;
    postOrder_simple_bst(root->left);    postOrder_simple_bst(root->right);       printf("%d, ",root->data);
}
int main() {

    //             50
    //           /    \
    //         30      70
    //        /  \    /  \
    //      20   40  60   80
    //     /     /      \
    //   10     35       65
    simple_bst* bst = NULL;
    bst = insert_simple_bst(bst, 50);
    bst = insert_simple_bst(bst, 30);
    bst = insert_simple_bst(bst, 70);
    bst = insert_simple_bst(bst, 20);
    bst = insert_simple_bst(bst, 40);
    bst = insert_simple_bst(bst, 60);
    bst = insert_simple_bst(bst, 80);
    bst = insert_simple_bst(bst, 10);
    bst = insert_simple_bst(bst, 35);
    bst = insert_simple_bst(bst, 65);
    // printf("%d",bst->data);
    if(search_bst(bst,890)) printf("True");
    else printf("False");
    printf("\n");
    delNode(bst,40);
    if(search_bst(bst,50)) printf("True");
    else printf("False");
    printf("\n");
    preOrder_simple_bst(bst);
    printf("\n");
    inOrder_simple_bst(bst);
    printf("\n");
    postOrder_simple_bst(bst);
    printf("\n");
}
