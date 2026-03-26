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
int** matrix_formation_for_determinant(int** matrix,int row,int col) {
    int **matrix_for_determinant = (int**)malloc(row * sizeof(int*));
    for (int i=0; i<row; i++) {
        int* array = (int*)malloc(((2*col)-1) * sizeof(int));
        for (int j=0; j<col; j++)               array[j]=matrix[i][j];
        for (int j=col; j<((2*col)-1); j++)           array[j]=matrix[i][j-col];
        matrix_for_determinant[i]=array;
    }
    return matrix_for_determinant;
}
void matrix_determinant_calculation_print(int** matrix,int row,int col) {
    int determinant_1=0,determinant_2=0,j =0,determinant;
    for (int i=0; i<col; i++) {
        int temp =1;
        for (j=0; j<col; j++) {
            //printf("%d %d\n",j,i+j);
            temp *= matrix[j][i+j];
        }
        //printf("%d\n",temp);
        determinant_1 += temp;
    }
    for (int i=0; i<col; i++) {
        int temp =1;
        for (j=0; j<col; j++) {
            //printf("%d %d\n",j,col-j-1+i);
            temp *= matrix[j][col-j-1+i];
        }
        //printf("%d\n",temp);
        determinant_2 += temp;
    }
    determinant = determinant_1 - determinant_2;
    printf ("%d",determinant);
}
void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int** determinant_calculation(int** matrix,int row,int col) {

}
int main () {
    int row,col,type;
    scanf("%d",&row);
    scanf("%d",&col);
    int** matrix = matrix_formation(row,col);
    int** matrix_for_determinant = matrix_formation_for_determinant(matrix,row,col);
    print_matrix(matrix,row,col);
    print_matrix(matrix_for_determinant,row,col+2);
    matrix_determinant_calculation_print(matrix_for_determinant,row,col);
    for (int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
}