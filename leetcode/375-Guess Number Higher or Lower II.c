/*
 * Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
 */
class Solution {
public:
    /* dp[i][j] means the minimal money needed to guess the range [i,j]
     * dp[i][j] = min{pivot + max(dp[i][pivot-1], dp[pivot+1][j])} (i<=pivot<=j)
     */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        int i, j, len, minval;
        for (len = 2; len <= n; len++) {
            for (i = 1; i <= n-len+1; i++) {
                minval = INT_MAX;
                for (j = i; j < i+len-1; j++) {
                    minval = min(minval, j+max(dp[i][j-1], dp[j+1][i+len-1]));
                }
                dp[i][i+len-1] = minval;
            }
        }
        return dp[1][n];
    }
};
