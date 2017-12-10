/*
 * Triangle
 *
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
 *
 */

/* C solution */
    int minimumTotal(vector<vector<int> > &t) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = t.size();
        vector<int> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = t[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }


/* Java solution */
public class Solution {
    public int minimumTotal(List<List<Integer>> t) {
        int n = t.size();
        int[] dp = new int[n+1];
        int i, j;
        for (i = n-1; i >= 0; i--) {
            for (j = 0; j <= i; j++) {
                dp[j] = t.get(i).get(j) + Math.min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
}

