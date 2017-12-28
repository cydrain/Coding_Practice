/*
 * Bomb Enemy
 *
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
 * (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted
 * point until it hits the wall since the wall is too strong to be destroyed.
 *
 * Note that you can only put the bomb at an empty cell.
 *
 * Example:
 * For the given grid
 *   0 E 0 0
 *   E 0 W E
 *   0 E 0 0
 *
 * return 3. (Placing a bomb at (1,1) kills 3 enemies)
 */
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> checkHorizon(m+1, vector<int>(n+1,0));
        vector<vector<int>> checkVertical(m+1, vector<int>(n+1,0));
        int i, j, maxkill = 0;
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (grid[i-1][j-1] == 'W') {
                    checkVertical[i][j] = 0;
                } else if (grid[i-1][j-1] == 'E') {
                    checkVertical[i][j] = checkVertical[i-1][j] + 1;
                } else {
                    checkVertical[i][j] = checkVertical[i-1][j];
                }
            }
        }
        for (i = m-1; i > 0; i--) {
            for (j = 1; j <= n; j++) {
                if (grid[i-1][j-1] == 'W') {
                    checkVertical[i][j] = 0;
                } else {
                    checkVertical[i][j] = max(checkVertical[i][j], checkVertical[i+1][j]);
                }
            }
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (grid[i-1][j-1] == 'W') {
                    checkHorizon[i][j] = 0;
                } else if (grid[i-1][j-1] == 'E') {
                    checkHorizon[i][j] = checkHorizon[i][j-1] + 1;
                } else {
                    checkHorizon[i][j] = checkHorizon[i][j-1];
                }   
            }
        }
        for (i = 1; i <= m; i++) {
            for (j = n-1; j > 0; j--) {
                if (grid[i-1][j-1] == 'W') {
                    checkHorizon[i][j] = 0;
                } else {
                    checkHorizon[i][j] = max(checkHorizon[i][j], checkHorizon[i][j+1]);
                }
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    maxkill = max(maxkill, checkHorizon[i+1][j+1]+checkVertical[i+1][j+1]);
                }
            }
        }
        return maxkill;
    }
};


class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int i, j, row = grid.size(), col, result, head, tail;
        if(row == 0 || (col = grid[0].size()) == 0)
            return 0;
        vector<vector<int> > count(row, vector<int>(col, 0));
        for(i = 0; i < row; i++) {
            for(head = tail = j = 0; j < col; j++) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[i][col - 1 - j] = grid[i][col - 1 - j] != '0' ? 0 : (count[i][col - 1 - j] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[i][col - 1 - j] == 'W' ? 0 : (tail + (grid[i][col - 1 - j] == 'E' ? 1 : 0));
            }
        }
        for(j = 0; j < col; j++) {
            for(head = tail = i = 0; i < row; i++) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[row - 1 - i][j] = grid[row - 1 - i][j] != '0' ? 0 : (count[row - 1 - i][j] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[row - 1 - i][j] == 'W' ? 0 : (tail + (grid[row - 1 - i][j] == 'E' ? 1 : 0));
            }
        }
        for(i = result = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                result = max(result, count[i][j]);
            }
        }
        return result;
    }
};
