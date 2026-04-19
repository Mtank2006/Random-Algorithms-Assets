#include <stdio.h>
#include <stdlib.h>
typedef struct simple_bt
{
    int data;
    struct simple_bt * left , * right;
}simple_bt;
simple_bt* create_root(int data) {
    simple_bt* new_block = (simple_bt*)malloc(sizeof(simple_bt));
    new_block->data = data;
    new_block->left = NULL;
    new_block->right = NULL;
    return new_block;
}
void preOrder_simple_bt(simple_bt* root) {
    if (root == NULL)       return;
    printf("%d, ",root->data);          preOrder_simple_bt(root->left);         preOrder_simple_bt(root->right);
}
void inOrder_simple_bt(simple_bt* root) {
    if (root == NULL)       return;
    inOrder_simple_bt(root->left);      printf("%d, ",root->data);              inOrder_simple_bt(root->right);
}
void postOrder_simple_bt(simple_bt* root) {
    if (root == NULL)       return;
    postOrder_simple_bt(root->left);    postOrder_simple_bt(root->right);       printf("%d, ",root->data);
}
int height_simple_bt(simple_bt* root) {
    if (root == NULL)       return 0;
    int lheight = height_simple_bt(root->left);
    int rheight = height_simple_bt(root->right);
    return (lheight > rheight ? lheight : rheight) + 1;
}
int get_data_level_simple_bt(simple_bt* root, int target, int level) {
    if (root == NULL)       return -1;
    if (root->data == target) {
        return level;
    }
    int left = get_data_level_simple_bt(root->left, target, level + 1);
    if (left != -1) 
        return left;
    return get_data_level_simple_bt(root->right, target, level + 1);
}
int if_root_exists(simple_bt* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    return if_root_exists(root->left, key) || if_root_exists(root->right, key);
}
int find_parent(simple_bt* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if ((root->left && root->left->data == key) || (root->left && root->right->data == key)) {
        return root->data;
    }
    int left = find_parent(root->left, key);
    if (left != -1) return left;
    return find_parent(root->right, key);
}
void print_leaf(simple_bt* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        printf("%d, ",root->data);
        return;
    }
    print_leaf(root->left);
    print_leaf(root->right);
    return;
}
void insert_element() {}
int main() {
    //       5
    //      / \
    //     12   13
    //    /  \    \
    //   7    14   2
    //  / \  /  \  / \
    // 17 23 27 3  8  11

    simple_bt* root = create_root(5);

    root->left = create_root(12);
    root->right = create_root(13);

    root->left->left = create_root(7);
    root->left->right = create_root(14);

    root->right->right = create_root(2);

    root->left->left->left = create_root(17);
    root->left->left->right = create_root(23);

    root->left->right->left = create_root(27);
    root->left->right->right = create_root(3);

    root->right->right->left = create_root(8);
    root->right->right->right = create_root(11);

    // preOrder_simple_bt(root);
    // printf("\n");
    // inOrder_simple_bt(root);
    // printf("\n");
    // postOrder_simple_bt(root);
    // printf("\n");

    // printf("%d\n",height_simple_bt(root));

    // printf("%d\n",get_data_level_simple_bt(root,2,1));
    
    // if (if_root_exists(root, 27))
    //     printf("True");
    // else
    //     printf("False");

    // printf("\n");

    // printf("%d\n",find_parent(root,27));


    print_leaf(root);


}