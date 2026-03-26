#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
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
void heap_sort(int* arr, int start, int end, int mid, int size) {
    if (arr[start]>arr[end]) {
        swap(&arr[start],&arr[end]);
    }
}
void heap(int* arr, int start, int end, int size) {
    if (start>=end) {
        printf ("%d \n",arr[start]);
        return;
    }
    int mid = (start + end)/2;
    heap_sort(arr,start,end,mid,size);
    heap(arr,start,mid,size);
    printf ("%d   %d   %d \n",start,end,mid);
    heap_sort(arr,start,end,mid,size);

    heap(arr,mid+1,end,size);
    printf ("%d   %d   %d \n",start,end,mid);
    heap_sort(arr,start,end,mid,size);
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    heap(arr,0,size-1,size);
    print_array (arr,size);
}