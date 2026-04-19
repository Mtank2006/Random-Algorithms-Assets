#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list_doubly_circular  {
    int data;
    struct linked_list_doubly_circular* prev;
    struct linked_list_doubly_circular* next;
}node;
node* create_doubly_linked_list() {
    node* new_block = (node*)malloc(sizeof(node));
    new_block->prev = new_block;
    new_block->next = new_block;
    return new_block;
}
node* create_node_doubly_circular(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    return new_node;
}
void insert_after(node* pos, int data) {
    node* new_node = create_node_doubly_circular(data);
    new_node->next = pos->next;
    new_node->prev = pos;
    pos->next->prev = new_node;
    pos->next = new_node;
}
void insert_beginning(node* head, int data) {
    insert_after(head, data);
}
void insert_end(node* head, int data) {
    insert_after(head->prev, data);
}
void print_list(node* head) {
    node* temp = head->next;
    while (temp != head) 
    {
        printf("%d, ",temp->data);
        temp = temp->next;
    }
}
int main() {
    node* head = create_doubly_linked_list();
    insert_beginning(head, 10);
    insert_beginning(head, 100);
    insert_end(head, 20);
    insert_beginning(head, 10);
    print_list(head);
}
