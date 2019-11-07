#include <stdio.h>

/* O(n**2) solution, best case */

#define COLUMN_SIZE 3
#define ROW_SIZE 4

/* Prints matrix row by row */
void print_matrix(int matrix[COLUMN_SIZE][ROW_SIZE])
{
    int i, j;

    for (i = 0; i < COLUMN_SIZE; i++)
        for (j = 0; j < ROW_SIZE; j++)
        {
            printf("%i", matrix[i][j]);
            j == COLUMN_SIZE
                ? printf("\n")
                : printf(", ");
        }
    printf("===============\n");
}

/* Set zeros for all values in a given row of a matrix */
void nullify_row(int matrix[COLUMN_SIZE][ROW_SIZE], int row)
{
    int i;

    for (i = 0; i < ROW_SIZE; i++)
        matrix[row][i] = 0;
}

/* Set zeros for all values in a given column of a matrix */
void nullify_column(int matrix[COLUMN_SIZE][ROW_SIZE], int column)
{
    int i;

    for (i = 0; i < COLUMN_SIZE; i++)
        matrix[i][column] = 0;
}

/* Sets zeros for all values in same row and column
   as existing zeroes */
void set_zeros(int matrix[COLUMN_SIZE][ROW_SIZE])
{
    int i, j;
    int columns[COLUMN_SIZE] = {0};
    int rows[ROW_SIZE] = {0};

    for (i = 0; i < COLUMN_SIZE; i++)
        for (j = 0; j < ROW_SIZE; j++)
            if (matrix[i][j] == 0)
            {
                columns[i] = 1;
                rows[j] = 1;
            }

    for (i = 0; i < ROW_SIZE; i++)
        if (rows[i] == 1)
            nullify_column(matrix, i);

    for (i = 0; i < COLUMN_SIZE; i++)
        if (columns[i] == 1)
            nullify_row(matrix, i);
}

int main(void)
{
    int matrix[3][4] = {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 0, 2}};

    print_matrix(matrix);
    set_zeros(matrix);
    print_matrix(matrix);

    return 0;
}