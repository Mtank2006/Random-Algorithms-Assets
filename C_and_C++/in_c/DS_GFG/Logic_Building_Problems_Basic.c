#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void Check_Even_or_Odd () {
    int n;      scanf("%d",&n);
    if (n%2==0) printf("Even\n");
    else        printf("Odd\n");
}
void Multiplication_Table() {
    int n;      scanf("%d",&n);
    for (int i = 0; i <= 10; i++)   printf("%d * %d = %d\n",n,i,n*i);
}
void Sum_of_Naturals() {
    int n;      scanf("%d",&n);     int sum = 0;
    while (n>0) sum += n--;
    printf("%d\n",sum);
}
void Sum_of_Squares() {
    int n;      scanf("%d",&n);     int sum = 0;
    while (n>0) sum += n * n, n--;
    printf("%d\n",sum);
}
void Swap_Two_Numbers() {
    int n1,n2;  scanf("%d %d",&n1,&n2);
    n1 = n1 + n2;   n2 = n1 - n2;   n1 = n1 - n2;
    printf("n1 = %d, n2 = %d",n1,n2);
}
void Closest_Number() {
    int n,m;    scanf("%d %d",&n,&m);
    int result = 0;
    // while () {

    // }
}
void Dice_Problem() {
    int n;      scanf("%d",&n);
    printf("%d",7-n);
}
int main() {
    int choice;
    scanf("%d",&choice);
    switch (choice) {
        case 1:     Check_Even_or_Odd();        break;
        case 2:     Multiplication_Table();     break;
        case 3:     Sum_of_Naturals();          break;
        case 4:     Sum_of_Squares();           break;
        case 5:     Swap_Two_Numbers();         break;
        case 6:     Closest_Number();           break;
        case 7:     Dice_Problem();             break;
    default:    break;
    }
}