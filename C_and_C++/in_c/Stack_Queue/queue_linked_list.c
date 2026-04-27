#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct queue_linked_list
{
    int arr[MAX];
    int front;
    int rear;
}qll;
qll* create_queue() {
    qll* queue = (qll*)malloc(sizeof(qll));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
qll* queue; 
void enqueue (int x) {
    if (queue->rear ==  MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = x;
}
void dequeue () {
    if (queue->front==-1||queue->front == queue->rear) {
        printf("Queue Underflow\n");
        return;
    }
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
}
void display (){
    if (queue->front == -1) {
        printf("Empty\n");
        return;
    }
    else {
        for (int i = queue->front; i <=queue->rear; i++) {
            printf("%d ",queue->arr[i]);
        }
    }
    printf("\n");
}
int main (){
    queue = create_queue();
    int option;
    while (1)
    {
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            int value;
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            exit(1);
            break;
        }
    }
}