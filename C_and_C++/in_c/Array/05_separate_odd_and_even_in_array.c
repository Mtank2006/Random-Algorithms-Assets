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
int* odd_list(int* arr,int array_size,int size) {
    int* array = (int*)malloc(array_size * sizeof(int));
    int count = 0;
    for (int i =0; i<size; i++) {
        if (arr[i]%2!=0) { array[count] = arr[i]; count++;
        }
    }
    return array;
}
int* even_list(int* arr,int array_size,int size) {
    int* array = (int*)malloc(array_size * sizeof(int));
    int count = 0;
    for (int i =0; i<size; i++) {
        if (arr[i]%2==0) { array[count] = arr[i]; count++;
        }
    }
    return array;
}
int* count_odd_even_in_array(int* array,int size) {
    int* odd_even = (int*)calloc(2, sizeof(int));
    for (int i = 0; i<size; i++) {
        if (array[i]%2!=0) odd_even[0]++;
        else odd_even[1]++;
    }
    return odd_even;
}
void print_array(int* array,int size) {
    for (int i=0; i<size; i++) {
        printf("%d\n",array[i]);
    }
}
int main() {
    int size;
    scanf("%d\n",&size);
    int* arr = input_array(size);
    int* o_e_count=count_odd_even_in_array(arr,size);
    int* odd=odd_list(arr,o_e_count[0],size);
    int* even=even_list(arr,o_e_count[1],size);
    printf ("Odd list\n");
    print_array(odd,o_e_count[0]);
    printf ("Even list\n");
    print_array(even,o_e_count[1]);
}