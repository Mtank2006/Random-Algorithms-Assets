#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list_1D_node
{
    int data1;
    int data2;
    // long long data3;
    // int* p;
    struct linked_list_1D_node* next;
    // struct linked_list_1D_node* prev;
}linked_list_1D_node;
linked_list_1D_node* create_block_linked_list_1D_node(int data) {
    linked_list_1D_node* new_block = (linked_list_1D_node*)malloc(sizeof(linked_list_1D_node));
    new_block->data1 = data;
    new_block->next = NULL;
    new_block->data2 = 1;
    return new_block;
}
// void insert_in_linked_list_1D(linked_list_1D_node* head,int data) {
//     linked_list_1D_node* new_block = create_block_linked_list_1D_node(data);
//     new_block->next = head;
//     head = new_block;
// }
void insert_in_linked_list_1D(linked_list_1D_node** head,int data) {
    linked_list_1D_node* new_block = create_block_linked_list_1D_node(data);
    new_block->next = *head;    
    *head = new_block;
    // new_block = *head;

}
void print_linked_list_1D(linked_list_1D_node* head) {
    while (head != NULL)
    {
        printf("%d  %d  , ",head->data1,head->data2);
        head = head->next;
    }
    printf("\n");
}
void address1(linked_list_1D_node** ptr,char* what) {
    printf("%p  %s",(void*)ptr,what);
    printf("\n");
}
void address2(linked_list_1D_node* ptr,char* what) {
    printf("%p  %s",(void*)ptr,what);
    printf("\n");
}
void address3(int* ptr,char* what) {
    printf("%p  %s",(void*)ptr,what);
    printf("\n");
}
void delete_value_linked_list_1D() {
    int d;
}
int main() {
    linked_list_1D_node* linked_list = create_block_linked_list_1D_node(10);
    insert_in_linked_list_1D(&linked_list,20);
    insert_in_linked_list_1D(&linked_list,30);
    printf("%zu\n",sizeof(linked_list_1D_node));
    // insert_in_linked_list_1D(&linked_list,20);
    // insert_in_linked_list_1D(&linked_list,20);
    print_linked_list_1D(linked_list);
    address1(&linked_list,"main_location");
    address2(linked_list,"main_first");
    address3(&(linked_list->data1),"list_d1");
    address3(&(linked_list->data2),"list_d2");
    address2((*linked_list).next,"list_first");
    address3(&(*linked_list).next->data1,"list_d1");
    address3(&(*linked_list).next->data2,"list_d2");
    address2((*linked_list).next->next,"list_second");
    address3(&(*linked_list).next->next->data1,"list_d1");
    address3(&(*linked_list).next->next->data2,"list_d2");
    address2((*linked_list).next->next->next,"list_third");
}