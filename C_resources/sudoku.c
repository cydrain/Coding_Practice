#include <stdio.h>
#define boolean int
#define TRUE 1
#define FALSE 0

boolean valid(int vec[9])
{
    int i;
    boolean flag[9] = {0};

    for(i=0; i<9; i++) {
        if (vec[i] != 0) {
            if (flag[vec[i]-1]) 
                return FALSE;
            else
                flag[vec[i]-1] = TRUE;
        }
    }
    return TRUE;
}

boolean check_sudoku(int sudoku[9][9], int row, int col)
{
    int vec[9];
    int row_sta, row_end;
    int col_sta, col_end;
    int i, j, k=0;

    row_sta = row/3*3;
    row_end = row_sta + 3;
    col_sta = col/3*3;
    col_end = col_sta + 3;

    // check row
    if (!valid(sudoku[row]))
        return FALSE;

    // check colomn
    for (i = 0; i < 9; i++) {
        vec[i] = sudoku[i][col];
    }
    if (!valid(vec))
        return FALSE;

    for(i=row_sta; i<row_end; i++) {
        for(j=col_sta; j<col_end; j++) {
            vec[k++] = sudoku[i][j];
        }
    }
    if (!valid(vec))
        return FALSE;
    
    return TRUE;
}

boolean find_first_empty(int sudoku[9][9], int* row, int* col)
{
    int i, j;
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if (sudoku[i][j] == 0) {
                *row = i;
                *col = j;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void show_sudoku(int sudoku[9][9])
{
    int i, j;

    printf("\nSolution:\n");
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

boolean solve_sudoku(int sudoku[9][9], int level)
{
    int i, j, k;
    boolean result = FALSE;
    
    if (!find_first_empty(sudoku, &i, &j)) {
        return TRUE;
    }
        
    for (k = 1; k <= 9; k++) {
        sudoku[i][j] = k;
        printf("\n%d: (%d,%d) -> %d",level, i, j, k);
        if (check_sudoku(sudoku, i, j) && solve_sudoku(sudoku, level+1)) {
            return TRUE;
        }
        else {
            sudoku[i][j] = 0;
        }
    }

    return FALSE;
}


int main()
{
    int  sudoku[9][9] = {{9,0,0,0,0,0,3,0,7},
                         {5,0,6,0,9,0,0,1,0},
                         {0,0,3,0,6,0,0,0,5},
                         {0,0,1,0,0,9,0,3,6},
                         {4,0,0,0,0,5,0,9,1},
                         {0,9,0,8,0,0,0,0,0},
                         {3,6,0,0,0,4,0,0,0},
                         {0,4,0,0,5,0,6,0,0},
                         {0,0,0,0,0,0,5,8,0}};

    if (solve_sudoku(sudoku, 0)) {
        show_sudoku(sudoku);
    }
    else {
        printf("\nFail");
    }

    return 1;
}

