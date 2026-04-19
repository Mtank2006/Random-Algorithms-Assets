#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int front = -1;
int rear = -1;
int Queue[MAX];
void push (int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    Queue[rear] = x;
}
void pop () {
    if (front==-1||front>rear) {
        printf("Queue Underflow\n");
        return;
    }
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}
void display (){
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    else {
        for (int i = front; i <=rear; i++) {
            printf("%d ",Queue[i]);
        }
    }
    printf("\n");
}
int main (){
    int option;
    while (1)
    {
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            int value;
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
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
