#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list * next;
}linked_list;
linked_list* create_node(int data) {
    linked_list* newNode = (linked_list*)malloc(sizeof(linked_list));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void insert_front(linked_list** head, int data) {
    linked_list* newNode = create_node(data);
    newNode->next = *head;
    *head = newNode;
}
void insert_end(linked_list** head, int data) {
    linked_list* newNode = create_node(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    linked_list* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
}
void merge_sorted_linked_list(linked_list* list1, linked_list* list2) {
    if (list1 == NULL) return;
    linked_list* temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    // list1 = temp;
}
int main() {
    linked_list* l1 = NULL;
    linked_list* l2 = NULL;
    insert_end(&l1,10);
    insert_end(&l1,20);
    printf("%d\n",l1->next->data);
    insert_end(&l2,40);
    insert_end(&l2,50);
    printf("%d\n",l2->next->data);
    merge_sorted_linked_list(l1,l2);
    printf("%d\n",l1->next->next->data);

}