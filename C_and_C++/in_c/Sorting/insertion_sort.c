#include <stdio.h>
#include <stdlib.h>
void insertion_comparision(int* arr, int current, int size) {
    while (current > 0 && arr[current] < arr[current - 1]) {
        int temp = arr[current-1];
        arr[current-1] = arr[current];
        arr[current] = temp;
        current --;
    }
}
void insertion_main (int* arr,int size){
    for (int i=1; i<size;i++) {
        insertion_comparision(arr,i,size);
    }
}
int* input_array(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i=0; i<size; i++) {
        scanf("%d",&array[i]);
    }
    return array;
}
void print_array(int* array,int size) {
    for (int i=0; i<size; i++) {
        printf("%d ",array[i]);
    }
}
int main() {
    int size;
    scanf ("%d",&size);
    int* arr = input_array(size);
    insertion_main(arr,size);
    print_array(arr,size);
}