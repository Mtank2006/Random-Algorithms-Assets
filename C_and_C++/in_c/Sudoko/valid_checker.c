#include <stdio.h>
#include <stdlib.h>
#define LOOP(i,a,b,c) for(int i = (a); i < (b); i += (c))
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
int is_sudoku_valid(int** sudoku, int row, int col) {
    int* visited = (int*)malloc(10*sizeof(int));
    LOOP(r,0,10,1){
        visited[r] = -1;
    }
    LOOP(i,0,row,1) {
        LOOP(j,0,col,1) {
            if (sudoku[i][j] != 0){
                if (visited[sudoku[i][j]]==i) {
                    free(visited);
                    return 0;
                }
                else {
                    visited[sudoku[i][j]]=i;
                }
            }
        }
        LOOP(r,0,10,1){
        visited[r] = -1;
        }
    }
    LOOP(r,0,10,1){
        visited[r] = -1;
    }
    LOOP(j,0,row,1) {
        LOOP(i,0,col,1) {
            if (sudoku[i][j] != 0){
                if (visited[sudoku[i][j]]==j) {
                    free(visited);
                    return 0;
                }
                else {
                    visited[sudoku[i][j]]=j;
                }
            }
        }
        LOOP(r,0,10,1){
        visited[r] = -1;
        }
    }
    LOOP(r,0,10,1){
        visited[r] = -1;
    }
    int block = 0;
    LOOP(bi,0,row,3) {
        LOOP(bj,0,col,3) {
            LOOP(i,bi,bi+3,1){
                LOOP(j,bj,bj+3,1){
                if (sudoku[i][j] != 0){
                    if (visited[sudoku[i][j]]==block) {
                        free(visited);
                        return 0;
                    }
                    else {
                        visited[sudoku[i][j]]=block;
                    }
                    }
                }
            }
        block++;
        }
    }
    free(visited);
    return 1;
}
int main () {
    int** sudoku = matrix_formation(9,9);
    // print_matrix(sudoku,9,9);
    if (is_sudoku_valid(sudoku,9,9)) {
        printf("Valid sudoku");
    }
    else {
        printf("Not a valid sudoku");
    }
}