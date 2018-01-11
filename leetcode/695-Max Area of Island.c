/*
 * Max Area of Island

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0. 
 */
class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        vector<int> dir({1,0,-1,0,1});
        int area = 0, x, y, row, col, k;
        grid[i][j] = 0;
        q.emplace(i,j);
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            area++;
            for (k = 0; k < 4; k++) {
                x = row + dir[k];
                y = col + dir[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    grid[x][y] = 0;
                    q.emplace(x, y);
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int maxarea = 0, area, i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j]) {
                    maxarea = max(maxarea, bfs(grid, i, j));
                }
            }
        }
        return maxarea;
    }
};
