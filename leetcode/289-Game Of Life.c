/*
 * Game of Life
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply as
 * Life, is a cellular automaton devised by the British mathematician John Horton
 * Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal, vertical,
 * diagonal) using the following four rules (taken from the above Wikipedia article):
 *  Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 *  Any live cell with two or three live neighbors lives on to the next generation.
 *  Any live cell with more than three live neighbors dies, as if by over-population..
 *  Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *
 * Write a function to compute the next state (after one update) of the board given
 * its current state.
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = (m ? board[0].size() : 0);
        int i, j, x, y, count;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                count = 0;
                for (x = max(i-1,0); x < min(i+2,m); x++) {
                    for (y = max(j-1,0); y < min(j+2,n); y++) {
                        if (board[x][y] & 0x1) count++;
                    }
                }
                cout << count << endl;
                // if has 3 neighbors, it will keep alive or change alive
                // if has 2 neighbors, it will keep alive
                if (count == 3 || (count-board[i][j] == 3)) {
                    board[i][j] |= 2;
                }
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
