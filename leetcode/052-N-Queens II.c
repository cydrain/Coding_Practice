/*
 * N-Queens II
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number 
 * of distinct solutions.
 *
 */

    bool conflict(vector<int> &state, int nextX, int nextY) {
        for (int i = 0; i < nextX; i++) {
            if (nextY == state[i] || abs(nextY-state[i]) == nextX-i) {
                return true;
            }
        }
        return false;
    }
    int permute(int n, vector<int> &state, int row) {
        int sum = 0;
        if (row >= n) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (!conflict(state, row, i)) {
                state[row] = i;
                sum += permute(n, state, row+1);
            }
        }
        return sum;
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> state(n);
        return permute(n, state, 0);
    }




    bool conflict(vector<int> &board, int nextY) {
        int nextX = board.size();
        for (int i = 0; i < nextX; i++) {
            if (nextY == board[i] || (nextX-i) == abs(nextY-board[i])) {
                return true;
            }
        }
        return false;
    }
    void totalNQueens(int n, vector<int> &board, int &r) {
        if (board.size() == n) {
            r++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (conflict(board, i)) continue;
            board.push_back(i);
            totalNQueens(n, board, r);
            board.pop_back();
        }
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> board;
        int r = 0;
        totalNQueens(n, board, r);
        return r;
    }
