#include <stdio.h>
#include <stdlib.h>
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

int* find_the_pair(int* array, int size, int target) {
    int found;
    int* pair = (int*)malloc(2 * sizeof(int));
    for (int i=0; i<size; i++) {
        if (found ==1) {
            break;
        }
        for (int j=0; j<size; j++) {
            if (array[i]+array[j]==target && i!=j) {
                pair[0] = array[i];
                pair[1] = array[j];
            }
        }
    }
    return pair;
    }
    
int* sort_aesc_array(int* array, int size) {
    int temp;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1; j++) {
            if (array[j]>array[j+1]) {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}
void print_array(int* array,int size) {
    for (int i=0; i<size; i++) {
        printf("%d\n",array[i]);
    }
}
int main () {
    int size,target;
    scanf ("%d",&size);
    int* arr = input_array(size);
    scanf ("%d",&target);
    int* arr_sorted = sort_aesc_array(arr,size);
    print_array(arr_sorted,size);
    int* pair = find_the_pair(arr_sorted,size,target);
    print_array(pair,2);
}