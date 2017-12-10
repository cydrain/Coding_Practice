/*
 * Word Search
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent
 * cell, where "adjacent" cells are those horizontally or vertically
 * neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 *
 * Given board =
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 *
 *  word = "ABCCED", -> returns true,
 *  word = "SEE", -> returns true,
 *  word = "ABCB", -> returns false.
 *
 */

bool exist(vector<vector<char> > &board, vector<vector<bool> > &visited, int idx, int x, int y, string &word) {
    if (idx == word.length()) return true;
    if (x < 0 || x >= board.size()) return false;
    if (y < 0 || y >= board[0].size()) return false;
    if (board[x][y] != word[idx]) return false;
    if (visited[x][y]) return false;
    visited[x][y] = true;
    bool ret = exist(board, visited, idx+1, x-1, y, word) ||
               exist(board, visited, idx+1, x+1, y, word) ||
               exist(board, visited, idx+1, x, y-1, word) ||
               exist(board, visited, idx+1, x, y+1, word);
    visited[x][y] = false;
    return ret;
}
bool exist(vector<vector<char> > &board, string word) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0] && 
                exist(board, visited, 0, i, j, word)) {
                return true;
            }
        }
    }
    return false;
}
