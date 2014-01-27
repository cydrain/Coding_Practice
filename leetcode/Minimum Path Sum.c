/*
 * Minimum Path Sum
 *
 * Given a m x n grid filled with non-negative numbers, find a path from
 * top left to bottom right which minimizes the sum of all numbers along
 * its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 */

    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int i, j;
        
        dp[m-1][n-1] = grid[m-1][n-1];
        for (i = m-2; i >= 0; i--) {
            dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        }
        for (j = n-2; j >= 0; j--) {
            dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
        }
        for (i = m-2; i >= 0; i--) {
            for (j = n-2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
