/*
 * Pacific Atlantic Water Flow
DescriptionHintsSubmissionsDiscussSolution

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

    The order of returned grid coordinates does not matter.
    Both m and n are less than 150.

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
 */
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visit, int x, int y) {
        int m = matrix.size();
        int n = matrix[0].size();
        visit[x][y] = true;
        if (x > 0   && !visit[x-1][y] && matrix[x-1][y] >= matrix[x][y]) dfs(matrix, visit, x-1, y);
        if (x < m-1 && !visit[x+1][y] && matrix[x+1][y] >= matrix[x][y]) dfs(matrix, visit, x+1, y);
        if (y > 0   && !visit[x][y-1] && matrix[x][y-1] >= matrix[x][y]) dfs(matrix, visit, x, y-1);
        if (y < n-1 && !visit[x][y+1] && matrix[x][y+1] >= matrix[x][y]) dfs(matrix, visit, x, y+1);
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        int i, j;
        for (i = 0; i < m; i++) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n-1);
        }
        for (j = 1; j < n; j++) {
            dfs(matrix, pacific, 0, j);
        }
        for (j = 0; j < n-1; j++) {
            dfs(matrix, atlantic, m-1, j);
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back(make_pair(i,j));
                }
            }
        }
        return res;
    }
};
