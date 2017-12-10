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

/* C solution */
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


class Solution {
public:
    void bfs(vector<vector<char>> &board, int x, int y) {
        queue<pair<int,int>> q;
        int m = board.size();
        int n = board[0].size();
        int i, j;
        
        board[x][y] = '+';
        q.emplace(x, y);
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            
            if (i > 0 && board[i-1][j] == 'O') {
                board[i-1][j] = '+';
                q.emplace(i-1, j);
            }
            if (i < m-1 && board[i+1][j] == 'O') {
                board[i+1][j] = '+';
                q.emplace(i+1,j);
            }
            if (j > 0 && board[i][j-1] == 'O') {
                board[i][j-1] = '+';
                q.emplace(i, j-1);
            }
            if (j < n-1 && board[i][j+1] == 'O') {
                board[i][j+1] = '+';
                q.emplace(i, j+1);
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m <= 2) return;
        int n = board[0].size();
        if (n <= 2) return;
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) &&
                    board[i][j] == 'O') {
                    bfs(board, i, j);
                }
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == '+') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


/* Java solution */
class Pair {
    public final int first;
    public final int second;
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class Solution {
    public void bfs(char[][] board, int x, int y) {
    	int m = board.length;
    	int n = board[0].length;
        Queue<Pair> q = new LinkedList<>();
        int i, j;
        board[x][y] = '.';
        q.offer(new Pair(x,y));
        while (q.size() != 0) {
            i = q.peek().first;
            j = q.peek().second;
            q.poll();
            board[i][j] = '.';
            if (i > 0 && board[i-1][j] == 'O') {
            	board[i-1][j] = '.';
            	q.offer(new Pair(i-1, j));
            }
            if (i < m-1 && board[i+1][j] == 'O') {
            	board[i+1][j] = '.';
            	q.offer(new Pair(i+1, j));
            }
            if (j > 0 && board[i][j-1] == 'O') {
            	board[i][j-1] = '.';
            	q.offer(new Pair(i, j-1));
            }
            if (j < n-1 && board[i][j+1] == 'O') {
            	board[i][j+1] = '.';
            	q.offer(new Pair(i, j+1));
            }
        }
    }
    public void solve(char[][] board) {
        int m = board.length;
        if (m <= 2) return;
        int n = board[0].length;
        if (n <= 2) return;
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) &&
                    (board[i][j] == 'O')) {
                	bfs(board, i, j);
                }
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}

