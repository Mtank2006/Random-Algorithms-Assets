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
/*void print_array(int* array,int size) {
    for (int i=0; i<size; i++) {
        printf("%d\n",array[i]);
    }
}*/
int count_duplicate_in_array(int* array,int size) {
    int visited[size];
    for (int i=0; i<size; i++) visited[i] =0;
    int count =0;
    for (int i=0; i<size; i++) {
        if (visited[i]==1) continue;
        int duplicates =0;
        for (int j=i+1; j<size; j++) {
            if (array[i]==array[j]) {
                visited[j]=1;
                duplicates ++;
            }
        }
        count += duplicates; 
    }
    return count;
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    int counter=count_duplicate_in_array(arr,size);
    printf("%d",counter);
}