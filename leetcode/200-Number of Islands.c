/*
 * Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3

 */

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        grid[x][y] = '0';
        if (x > 0   && grid[x-1][y] == '1') dfs(grid, x-1, y);
        if (x < m-1 && grid[x+1][y] == '1') dfs(grid, x+1, y);
        if (y > 0   && grid[x][y-1] == '1') dfs(grid, x, y-1);
        if (y < n-1 && grid[x][y+1] == '1') dfs(grid, x, y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = (m ? grid[0].size() : 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i, j, cnt = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        int i, j;
        queue<pair<int,int>> q;
        grid[x][y] = '0';
        q.emplace(x, y);
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (i > 0 && grid[i-1][j] == '1') {
                grid[i-1][j] = '0';
                q.emplace(i-1, j);
            }
            if (i < m-1 && grid[i+1][j] == '1') {
                grid[i+1][j] = '0';
                q.emplace(i+1, j);
            }
            if (j > 0 && grid[i][j-1] == '1') {
                grid[i][j-1] = '0';
                q.emplace(i, j-1);
            }
            if (j < n-1 && grid[i][j+1] == '1') {
                grid[i][j+1] = '0';
                q.emplace(i, j+1);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int i, j, cnt = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
