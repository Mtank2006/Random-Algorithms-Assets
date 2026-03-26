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
void print_matrix_pattern(int**matrix,int row,int col,int type){
    int limit,change,space_required,start,s4;   
    if (type ==1) {
        limit =col;     change =-1;     space_required = 0;     start =0;
    }
    else if (type ==3)
    {   limit =1;       change = 1;     space_required = 0;     start =0;
    }
    else if (type ==2)
    {
        limit =col;     change = 0;     space_required = 1;     start =0;
    }
    else if (type ==4)
    {
        limit =col;     change = 0;     space_required = 1;     start =col-1;
    }
    for (int i = 0; i < row; i++) {
        if (space_required ==1) {   
            for (int k=0; k<start; k++) {
                printf("  ");
            }
        }
        for (int j = start; j < limit; j++) {
            printf("%d ", matrix[i][j]);
        }
        if (space_required ==1) {   
            if (type==2)    start ++;
            if (type==4)    start --;
        }
        printf("\n");
        limit +=change;
    }
}
/*void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}*/
int main () {
    int row,col,type;
    scanf("%d",&row);
    scanf("%d",&col);
    int** matrix = matrix_formation(row,col);
    scanf("%d",&type);
    //type 1 :- upper right
    //type 2 :- upper left
    //type 3 :- lower right 
    //type 4 :- lower left
    print_matrix_pattern(matrix,row,col,type);
    //print_matrix(matrix,row,col);
    for (int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
}
