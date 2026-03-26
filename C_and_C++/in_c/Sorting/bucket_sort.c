#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
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
    for (int i=1; i<size ; i++) {
        if (arr[i]>l) l = arr[i];
        else if (arr[i]<s) s = arr[i]; 
    }
    pair[0] = s;
    pair[1] = l;
    return pair;
    // printf("%d   %d",s,l);
}
int* partition_size_decider(int* arr, int size,int s, int l) {
    // int partition_size;
    int temp = 2;
    int count = 1;
    while ( temp < size)
    {
        temp *= 2;
        count++;
    }
    // printf("%d",temp);
    int partition_size = (l-s)/count;
    // printf("%d",(l-s)/count);
    int* partition_info_arr = (int*)malloc(sizeof(int)*7); //needs modification
    partition_info_arr[0] = temp;     // upto range
    partition_info_arr[1] = count;    // no of buckets
    partition_info_arr[2] = s;
    partition_info_arr[3] = l;
    partition_info_arr[4] = partition_size;
    return partition_info_arr;
}
int** array_maker_and_give_made_array_address(int* partition_info_arr) {
    int** bucket_arr = (int**)malloc(partition_info_arr[1]*sizeof(int*));
    for(int i = 0; i < partition_info_arr[1]+1; i++) {
        // int* temp_arr = (int*)malloc(10*sizeof(int)); // remove this
        int* temp_arr = (int*)malloc(partition_info_arr[4]*sizeof(int));
        bucket_arr[i] = temp_arr;
        // free(temp_arr);
    }
    return bucket_arr;
}
int* filling_bucket(int** bucket_arr,int* arr,int* partition_info_arr,int size) {
    // int* bucket_arr_filling_counter = (int*)calloc(partition_info_arr[1],sizeof(int)); // needs modifi
    int* bucket_arr_filling_counter = (int*)calloc(partition_info_arr[1],sizeof(int)); // needs modifi
    for(int i =0;i < size; i++) {
        int temp = arr[i]/partition_info_arr[4];
        // printf("%d  ",temp);
        // printf("\n");
        // printf("%d",bucket_arr_filling_counter[temp]);
        // printf("\n");
        // bucket_arr[bucket_arr_filling_counter[temp]][temp] = arr[i];
        // bucket_arr[temp][bucket_arr_filling_counter[temp]] = arr[i];
        bucket_arr[temp][bucket_arr_filling_counter[temp]] = arr[i];
        bucket_arr_filling_counter[temp]++;
    }
    return bucket_arr_filling_counter;
}
void arranging_elements_in_bucket(int** bucket_arr, int* bucket_filling_counter, int* partition_info_arr) {
    for(int i = 0; i < partition_info_arr[4]; i++) {
        for(int j = 0; j < bucket_filling_counter[i] - 1; j++) {
            for(int k = 0; k < bucket_filling_counter[i] - j - 1; k++) {
                if (bucket_arr[i][k] > bucket_arr[i][k+1]) {
                    swap(&bucket_arr[i][k],&bucket_arr[i][k+1]);
                }
            }
        }
    }
}
void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void print_matrix_modified_size_detecter(int** matrix, int* bucket_arr_filling_counter, int count) {
    for (int i = 0; i < count; i++) { // need modifi
        for (int j = 0; j < bucket_arr_filling_counter[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void final_sorted_arr_maker(int** matrix, int* bucket_arr_filling_counter, int count, int* arr) {
    int temp = 0;
    for (int i = 0; i < count; i++) { // need modifi
        for (int j = 0; j < bucket_arr_filling_counter[i]; j++) {
            arr[temp] = matrix[i][j];
            temp++;
        }
    }
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    int* largest_smallest_pair = find_largest_smallest_in_arr(arr,size);
    // print_array (arr,size);

    int* partition_info_arr = partition_size_decider(arr,size,largest_smallest_pair[0],largest_smallest_pair[1]);
    int** bucket_arr = array_maker_and_give_made_array_address(partition_info_arr);
    // print_matrix(bucket_arr,partition_info_arr[1]+1,10);
    // print_matrix_modified_size_detecter(bucket_arr,bucket_arr_filling_counter,partition_info_arr[1]);
    int* bucket_arr_filling_counter = filling_bucket(bucket_arr,arr,partition_info_arr,size);
    // print_matrix(bucket_arr,partition_info_arr[1]+1,10);
    // print_matrix_modified_size_detecter(bucket_arr,bucket_arr_filling_counter,partition_info_arr[1]+1);
    arranging_elements_in_bucket(bucket_arr,bucket_arr_filling_counter,partition_info_arr);
    // print_matrix(bucket_arr,partition_info_arr[1]+1,10);
    // print_matrix_modified_size_detecter(bucket_arr,bucket_arr_filling_counter,partition_info_arr[1]+1);
    final_sorted_arr_maker(bucket_arr,bucket_arr_filling_counter,partition_info_arr[1]+1,arr);
    print_array (arr,size);
    free(arr);
    return 0;
}