#include <stdio.h>
#include <stdlib.h>
#define LOOP(iterator,start,end,change) for(int iterator = (start); iterator < (end); iterator+= (change))
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t; 
}
void selection_sort(int* arr, int size) {
    LOOP(i,0,size-1,1){
        int min_idx = i;
        LOOP(j,i+1,size,1){
            if (arr[j]<arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i)   swap(&arr[i],&arr[min_idx]);
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
int main () {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    selection_sort(arr,size);
    print_array(arr,size);
    free(arr);
}