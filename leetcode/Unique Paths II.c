/*
 * Unique Paths II
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique
 * paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 *
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 *
 */

    int uniquePathsWithObstacles(vector<vector<int> > &obs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obs.size();
        int n = obs[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int i, j;
        
        if (obs[m-1][n-1]) return 0;
        dp[m-1][n-1] = 1;
        for (i = m-2; i >= 0; i--) {
            dp[i][n-1] = obs[i][n-1] ? 0 : dp[i+1][n-1];
        }
        for (j = n-2; j >= 0; j--) {
            dp[m-1][j] = obs[m-1][j] ? 0 : dp[m-1][j+1];
        }
        for (i = m-2; i >= 0; i--) {
            for (j = n-2; j >= 0; j--) {
                dp[i][j] = obs[i][j] ? 0 : (dp[i+1][j] + dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
