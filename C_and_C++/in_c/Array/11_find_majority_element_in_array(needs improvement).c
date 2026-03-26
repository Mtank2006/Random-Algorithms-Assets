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
int find_freq_elements_in_array(int* array,int size) {
    int* visited = (int*)malloc(size * sizeof(int));
    int found =0,mid,element;
    if (size%2==0) {
            mid = size /2;
        }
    else {
        mid = (size +1)/2;
    }
    for (int i=0; i<size; i++) visited[i] =0;
    for (int i=0; i<size; i++) {
        if (found!=0) {
            break;
        if (visited[i]!=0) continue;
        int freq = 1;
            for (int j=i+1; j<size; j++) {
                if (array[i]==array[j]) {
                    visited[j]=1;
                    freq ++;
                }
            }
        if (freq==mid) {
            found=1;
            element=array[i];
        }
    }
    }
    return element;
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    int element = find_freq_elements_in_array(arr,size);
    printf ("%d",element);
}