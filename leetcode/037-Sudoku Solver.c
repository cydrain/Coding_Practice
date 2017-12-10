/*
 * Sudoku Solver
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution. 
 *
 */

bool isValidArray(vector<char> &v) {
    vector<bool> flag(v.size(), false);
    for (int i = 0; i < 9; i++) {
        if (v[i] == '.') continue;
        if (flag[v[i]-'1']) {
            return false;
        }
        else {
            flag[v[i]-'1'] = true;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char> > &board, int x, int y) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<char> v(9, '.');
    int i, j, k;
    int start_row, start_col;
    
    // check row
    if (!isValidArray(board[x])) return false;
    
    // check column
    for (i = 0; i < 9; i++) {
        v[i] = board[i][y];
    }
    if (!isValidArray(v)) return false;
    
    // check square
    start_row = x/3*3;
    start_col = y/3*3;
    k = 0;
    for (i = start_row; i < start_row+3; i++) {
        for (j = start_col; j < start_col+3; j++) {
            v[k++] = board[i][j];
        }
    }
    if (!isValidArray(v)) return false;
    
    return true;
}
bool findFirstEmpty(vector<vector<char> > &board, int &x, int &y) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSudokuHelper(vector<vector<char> > &board) {
    int x, y;
    char c;
    if (!findFirstEmpty(board, x, y)) {
        return true;
    }
    for (c = '1'; c <= '9'; c++) {
        board[x][y] = c;
        if (isValidSudoku(board, x, y) && solveSudokuHelper(board)) {
            return true;
        } 
        board[x][y] = '.';
    }
    return false;
}
void solveSudoku(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    solveSudokuHelper(board);
}
