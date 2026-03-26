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
void print_array(int* array,int size) {
    for (int i=0; i<size; i++) {
        printf("%d\n",array[i]);
    }
}
int* matrix_sum_rows_cols(int** matrix,int v1,int v2,int mode) {
    int* sum_matrix_row_col = (int*)calloc(v1,sizeof(int));
    for (int i=0; i<v1; i++) {
        for (int j=0; j<v2; j++) {
            if (mode ==0) 
            sum_matrix_row_col[i] += matrix[i][j];
            else sum_matrix_row_col[i] += matrix[j][i];
        }
    }
    return sum_matrix_row_col;
    //mode 0    v1 = row , v2 = col
    //mode 1    v1 = col , v2 = row
}
void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main () {
    int row,col;
    scanf("%d",&row);
    scanf("%d",&col);
    int** matrix = matrix_formation(row,col);
    print_matrix(matrix,row,col);
    int mode = 0;
    int* sum_row= matrix_sum_rows_cols(matrix,row,col,mode);
    mode = 1; 
    int* sum_col= matrix_sum_rows_cols(matrix,col,row,mode);
    printf ("Row Sum\n");
    print_array(sum_row,row);
    printf ("Col Sum\n");
    print_array(sum_col,col);
    for (int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
}