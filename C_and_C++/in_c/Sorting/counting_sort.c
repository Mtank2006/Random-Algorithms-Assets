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
int* find_largest_smallest_in_arr(int*arr , int size) {
    int* pair = (int*)malloc(2 *sizeof(int));
    int l=arr[0],s=arr[0];
    if (s>l) swap(&s,&l);
    for (int i=2; i<size ; i++) {
        if (arr[i]>l) l = arr[i];
        else if (arr[i]<s) s = arr[i]; 
    }
    pair[0] = s;
    pair[1] = l;
    return pair;
    // printf("%d   %d",s,l);
}
int* frequency_array_from(int* arr, int l, int size) {
    // int* frequency_array = (int*)malloc(l*sizeof(int));
    // for (int i=0; i<l; i++) {
    //     frequency_array[i]=0;
    // }
    int* frequency_array = (int*)calloc(l,sizeof(int));
    for (int i=0;i<size;i++) {
        frequency_array[arr[i]]++; 
    }
    return frequency_array;
}
void do_cumulative_sum_in_array(int* arr,int start,int size) { 
    for (int i =start+1;i<size;i++) {
        arr[i]=arr[i-1]+arr[i];
    }
}
void modify_initial_array(int* arr,int s,int l,int initial_size) {
    int count =0;
    for(int i = 0;i<=l;i++) {
        while (arr[i]>count) {
            arr[count] = i;
            count++; 
        }
    }
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    find_largest_smallest_in_arr(arr,size);
    int* pair = find_largest_smallest_in_arr(arr,size);
    int* frequency_array = frequency_array_from(arr,pair[1],size);
    do_cumulative_sum_in_array(frequency_array,pair[0],pair[1]+1);
    modify_initial_array(frequency_array,pair[0],pair[1],size);
    // printf("%d   %d",pair[0],pair[1]);
    // print_array (arr,size);
    print_array (frequency_array,size);
    // print_array (dup,pair[1]+1);
}