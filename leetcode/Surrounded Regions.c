/*
 * Surrounded Regions
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region .
 *
 * For example,
 *   X X X X
 *   X O O X
 *   X X O X
 *   X O X X
 *
 * After running your function, the board should be:
 *   X X X X
 *   X X X X
 *   X X X X
 *   X O X X
 * 
 */

    void solveHelper(vector<vector<char> > &board, int x, int y) {
        if (x < 0 || x >= board.size()) return;
        if (y < 0 || y >= board[0].size()) return;
        if (board[x][y] != 'O') return;
        board[x][y] = '.';
        solveHelper(board, x-1, y);
        solveHelper(board, x+1, y);
        solveHelper(board, x, y-1);
        solveHelper(board, x, y+1);
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        if (board.size() <= 2) return;
        if (board[0].size() <= 2) return;
        
        for (j = 0; j < board[0].size(); j++) {
            solveHelper(board, 0, j);
            solveHelper(board, board.size()-1, j);
        }
        for (i = 1; i < board.size()-1; i++) {
            solveHelper(board, i, 0);
            solveHelper(board, i, board[0].size()-1);
        }
        
        for (i = 0; i < board.size(); i++) {
            for (j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }




    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        if (m <= 2) return;
        int n = board[0].size();
        if (n <= 2) return;
        queue<pair<int,int> > q;
        int i, j, x, y;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if (board[i][j] == 'O') {
                        q.push(make_pair(i, j));
                    }
                }
            }
        }
        while (!q.empty()) {
            pair<int,int> node = q.front();
            q.pop();
            x = node.first;
            y = node.second;
            board[x][y] = '.';
            if (x > 0 && board[x-1][y] == 'O') {
                q.push(make_pair(x-1, y));
            }
            if (x < m-1 && board[x+1][y] == 'O') {
                q.push(make_pair(x+1, y));
            }
            if (y > 0 && board[x][y-1] == 'O') {
                q.push(make_pair(x, y-1));
            }
            if (y < n-1 && board[x][y+1] == 'O') {
                q.push(make_pair(x, y+1));
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }

