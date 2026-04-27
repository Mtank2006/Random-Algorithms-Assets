#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int top = -1;
int Stack[MAX];
void push (int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    Stack[top] = x;
}
void pop () {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top --;
}
void display (){
    if (top == -1) {
        printf("Empty\n");
        return;
    }
    else {
        for (int i = top; i >= 0; i--) {
            printf("%d ",Stack[i]);
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