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
void print_array(int* array,int size) {
    for (int i=0; i<size; i++) {
        printf("%d\n",array[i]);
    }
}
int* merge_two_array_same_size(int* array1,int*array2,int size) {
    int* array = (int*)malloc((2*size) * sizeof(int));
    for (int i=0; i<size; i++) array[i] = array1[i];
    for (int i=0; i<size; i++) array[i+size] = array2[i];
    return array;
}
int* sort_desc_array(int* array, int size) {
    int temp;
    for (int i=0; i<size-1; i++) {
        for (int j=i; j<size; j++) {
            if (array[i]<array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr1 = input_array(size);
    int* arr2 = input_array(size);
    int* arr = merge_two_array_same_size(arr1,arr2,size);
    int* arr_desc = sort_desc_array(arr,(2*size));
    print_array(arr_desc,(2*size));
}