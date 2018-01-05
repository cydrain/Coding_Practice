/*
 * Coin Change
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 *  coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Example 2:
 *  coins = [2], amount = 3
 * return -1. 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), i, j;
        vector<int> dp(amount+1, amount+1);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (i = 1; i <= amount; i++) {
            for (j = 0; j < n; j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                } else {
                    break;
                }
            }
        }
        return (dp[amount] > amount ? -1 : dp[amount]);
    }
};
