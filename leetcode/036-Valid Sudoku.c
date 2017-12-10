/*
 * Valid Sudoku
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
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
bool isValidSudoku(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<char> v(9, '.');
    int i, j;
    
    // check rows
    for (i = 0; i < 9; i++) {
        if (!isValidArray(board[i])) return false;
    }
    
    // check columns
    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) {
            v[i] = board[i][j];
        }
        if (!isValidArray(v)) return false;
    }
    
    // check squares
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            v[j] = board[i/3*3+j/3][i%3*3+j%3];
        }
        if (!isValidArray(v)) return false;
    }
    
    return true;
}
