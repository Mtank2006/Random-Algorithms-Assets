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
int* find_duplicate_in_array(int* array,int size) {
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i=0; i<size; i++) visited[i] =0;
    for (int i=0; i<size; i++) {
        if (visited[i]!=0) continue;
        for (int j=i+1; j<size; j++) {
            if (array[i]==array[j]) {
                visited[j]=1;
                visited[i]=1;
            }
        }
    }
    return visited;
}
void print_unique_in_array(int* visited, int* array,int size) {
    for (int i=0; i<size; i++) {
        if(visited[i]==0) printf("\n%d",array[i]);
    }
}
int main() {
    int size;
    scanf("%d",&size);
    int* arr = input_array(size);
    int* visited = find_duplicate_in_array(arr,size);
    print_unique_in_array(visited,arr,size);
}