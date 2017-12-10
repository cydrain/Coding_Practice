/*
 * Unique Binary Search Trees
 *
 * Given n, how many structurally unique BST's (binary search trees)
 * that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * 
 */

/* C solution */
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2) return 1;
        
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                f[i] += f[j] * f[i-j-1];
            }
        }
        
        return f[n];
    }


/* Java solution */
public class Solution {
    public int numTrees(int n) {
        if (n <= 1) return 1;
        int[] dp = new int[n+1];
        dp[0] = dp[1] = 1;
        int i, j;
        for (i = 2; i <= n; i++) {
            for (j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
}

