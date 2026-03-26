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
int** matrix_formation(int row,int col) {
    int **matrix = (int**)malloc(row * sizeof(int*));
    for (int i=0; i<row; i++) {
        matrix[i] = input_array(col);
    }
    return matrix;
}
void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int compare_two_matrices(int** matrix_1,int** matrix_2,int row,int col) {
    int until_equal=0;
    for (int i = 0; i < row; i++) {
        if (until_equal!=0) {
            break;
        }
        for (int j = 0; j < col; j++) {
            if (matrix_1[i][j]!=matrix_2[i][j]) {
                until_equal =1;
            }
        }
    }
    return until_equal;
}
int main () {
    int row,col;
    scanf("%d",&row);
    scanf("%d",&col);
    int** matrix_1 = matrix_formation(row,col);
    scanf("%d",&row);
    scanf("%d",&col);
    int** matrix_2 = matrix_formation(row,col);
    print_matrix(matrix_1,row,col);
    print_matrix(matrix_2,row,col);
    int until_equal = compare_two_matrices(matrix_1,matrix_2,row,col);
    if (until_equal!=0) {
            printf("Not Equal");
        }
    else {
        printf("Equal");
    }
    for (int i = 0; i < row; i++)
        free(matrix_1[i]);
    free(matrix_1);
    for (int i = 0; i < row; i++)
        free(matrix_2[i]);
    free(matrix_2);
}