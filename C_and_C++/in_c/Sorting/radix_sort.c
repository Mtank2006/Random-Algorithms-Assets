#include <stdio.h>
#include <stdlib.h>
// #include <math.h> 
// Pow returns doubles so it is of no use here
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
int find_digits_in_the_number(int num) {
    if (num ==0 ) return 1;
    int digits =0;
    for (int i = num ; i > 0 ; i/=10) {
        digits++;
    }
    return digits;
}
// void sort_given_place_value(int* arr, int place_value, int size) {
//     for(int i=0;i<size;i++) {
//         for(int j = i+1;j<size;j++) {
//             // if ((arr[i]%place_value)>(arr[j])%place_value) {
//             //     swap(&arr[i],&arr[j]);
//             // }
//             int di = (arr[i] / place_value) % 10;
//             int dj = (arr[j] / place_value) % 10;
//             if (di > dj) {
//                 swap(&arr[i], &arr[j]);
//             }
//         }
//     }
// }
void sort_given_place_value(int* arr, int place_value, int size) {
    int* output = (int*)malloc(size * sizeof(int));
    int count[10] = {0};

    // Count digit occurrences
    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / place_value) % 10;
        count[digit]++;
    }
    // print_array(count,10);
    // printf("\n");

    // Prefix sum (positions)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    print_array(count,10);
    printf("\n");

    // Build output array (right-to-left for stability)
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / place_value) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
        print_array(count,10);
        printf("\n");
    }
    print_array(output,size);
    printf("\n");
    // print_array(count,10);
    // printf("\n");
    // Copy back
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    // print_array(output,size);
    // printf("\n");

    // print_array(count,10);
    // printf("\n");

    free(output);
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    int* largest_smallest_pair = find_largest_smallest_in_arr(arr,size);
    int largest_num_digits = find_digits_in_the_number(largest_smallest_pair[1]);
    int p = 1;
    for (int i= 0; i<largest_num_digits; i++) {
        // printf("%d", p);
        sort_given_place_value(arr,p,size);
        p *= 10;

    }
    // sort_given_place_value(arr,10,size);
    print_array (arr,size);
    // printf("%d",(int)pow(10,largest_num_digits));
    free(arr);
    free(largest_smallest_pair);
    return 0;
}