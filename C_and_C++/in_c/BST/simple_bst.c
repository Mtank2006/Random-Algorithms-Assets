#include <stdio.h>
#include <stdlib.h>
typedef struct simple_bst
{
    int data;
    struct simple_bst * left , * right;
}simple_bst;
simple_bst* create_block_linked_list_1D_node(int data) {
    simple_bst* new_block = (simple_bst*)malloc(sizeof(simple_bst));
    new_block->data = data;
    new_block->left = NULL;
    new_block->right = NULL;
    return new_block;
}
void insert_in_linked_list_1D_left(simple_bst** head,int data) {
    simple_bst* new_block = create_block_linked_list_1D_node(data);
    new_block->left = *head;    
    *head = new_block;
}
void insert_in_linked_list_1D_right(simple_bst** head,int data) {
    simple_bst* new_block = create_block_linked_list_1D_node(data);
    new_block->right = *head;    
    *head = new_block;
}
int main() {
    simple_bst* bst = create_block_linked_list_1D_node(10);
    insert_in_linked_list_1D_left(&bst,20);
    insert_in_linked_list_1D_right(&bst,30);
    printf("%d",bst->data);

}
