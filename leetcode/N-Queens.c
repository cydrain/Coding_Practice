/*
 * N-Queens
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement,
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 */

    bool conflict(vector<int> state, int nextY) {
        int nextX = state.size();
        for (int i = 0; i < nextX; i++) {
            if (nextY == state[i] || abs(nextY-state[i]) == nextX-i) {
                return true;
            }
        }
        return false;
    }
    void solveNQueensHelper(int n, vector<int> &state, vector<vector<int> > &result) {
        if (state.size() == n) {
            result.push_back(state);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!conflict(state, i)) {
                state.push_back(i);
                solveNQueensHelper(n, state, result);
                state.pop_back();
            }
        }
    }
    vector<vector<string> > getResult(int n, vector<vector<int> > state) {
        vector<vector<string> > r;
        for (int i = 0; i < state.size(); i++) {
            vector<string> tmp(n, string(n, '.'));
            for (int j = 0; j < n; j++) {
                tmp[j][state[i][j]] = 'Q';
            }
            r.push_back(tmp);
        }
        return r;
    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> state;
        solveNQueensHelper(n, state, r);
        return getResult(n, r);
    }
