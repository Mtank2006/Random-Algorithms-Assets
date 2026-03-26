#include <stdio.h>
#include <stdlib.h>
void merge(int * arr,int start,int mid,int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}
void merge_sort(int * arr, int start , int end, int size) {
    if (start>=end) {
        return;
    }
    int mid = (start + end)/2;
    merge_sort (arr,start,mid,size);
    merge_sort (arr,mid+1,end,size);
    merge (arr,start,mid,end);
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
    // int arr[10] ={4,5,6,3,7,4,8,7,4,8};
    // size =10;
    merge_sort(arr,0,size-1,size);
    print_array(arr,size);
    // int a[10] ={4,5,6,3,7,4,8,7,4,8};

    // for (int i =0; i<(sizeof(a)/sizeof(a[0]));i++) {
        
    // }
}
