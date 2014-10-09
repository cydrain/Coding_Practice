/*
 * Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid 
 * (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point
 * in time. The robot is trying to reach the bottom-right
 * corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 */

    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int i, j;
        for (i = m-1; i >= 0; i--) {
            dp[i][n-1] = 1;
        }
        for (j = n-1; j >= 0; j--) {
            dp[m-1][j] = 1;
        }
        for (i = m-2; i >= 0; i--) {
            for (j = n-2; j >= 0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> block(m, vector<int>(n, 1));
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                block[i][j] = block[i+1][j] + block[i][j+1];
            }
        }
        return block[0][0];
    }

