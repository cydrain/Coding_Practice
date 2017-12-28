/*
 * Perfect Squares
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9. 
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        int i, j;
        dp[0] = 0, dp[1] = 1;
        for (i = 2; i <= n; i++) {
            for (j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
