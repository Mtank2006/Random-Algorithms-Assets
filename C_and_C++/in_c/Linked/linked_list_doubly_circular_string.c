#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct linked_list_doubly_circular  {
    char data[20];
    struct linked_list_doubly_circular* prev;
    struct linked_list_doubly_circular* next;
}node;
node* create_doubly_linked_list() {
    node* new_block = (node*)malloc(sizeof(node));
    new_block->prev = new_block;
    new_block->next = new_block;
    return new_block;
}
node* create_node_doubly_circular(char* data) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    return new_node;
}
void insert_after(node* pos, char* data) {
    node* new_node = create_node_doubly_circular(data);
    new_node->next = pos->next;
    new_node->prev = pos;
    pos->next->prev = new_node;
    pos->next = new_node;
}
void insert_beginning(node* head, char* data) {
    insert_after(head, data);
}
void insert_end(node* head, char* data) {
    insert_after(head->prev, data);
}
void print_list(node* head) {
    node* temp = head->next;
    while (temp != head) 
    {
        printf("%s, ",temp->data);
        temp = temp->next;
    }
}
int is_sorted(node* head) {
    node* temp = head->next;

    while (temp->next != head) {
        if (strcmp(temp->data, temp->next->data) > 0)
            return 0; // NOT sorted
        temp = temp->next;
    }
    return 1; // sorted
}
int main() {
    node* head = create_doubly_linked_list();
    insert_beginning(head, "NOEL");
    // insert_beginning(head, "SHERRY");
    // insert_end(head, "LEON");
    // insert_beginning(head, "ZENO");
    // insert_end(head, "GRACE");
    print_list(head);
    printf("\n");
    if (is_sorted(head)) printf("Sorted");
    else printf("Not Sorted");
}
