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
void solve_sudoku(int** sudoku,) {}
int main () {
    int row,col;
    // scanf("%d",&row);
    // scanf("%d",&col);
    row = 9;
    col = 9;
    int** sudoku = matrix_formation(row,col);
    print_matrix(sudoku,row,col);

    return 0;
}