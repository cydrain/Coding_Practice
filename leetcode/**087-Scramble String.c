/*
 * Scramble String
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it to
 * two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *            / \
 *           a   t
 *
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 *
 * For example, if we choose the node "gr" and swap its two children, it produces a
 * scrambled string "rgeat".
 *     rgeat
 *    /    \
 *   rg    eat
 *  / \    /  \
 * r   g  e   at
 *            / \
 *           a   t
 *
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces
 * a scrambled string "rgtae".
 *
 *     rgtae
 *    /    \
 *   rg    tae
 *  / \    /  \
 * r   g  ta  e
 *        / \
 *       t   a
 *
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
 *
 */

/* C solution */
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // f(i,j,n)=true iff s1[i:i+n) and s2[j:j+n) are scrambled.
        // so f(i,j,n) ||= (f(i,j,m) && f(i+m,j+m,n-m)) ||
        //                 (f(i,j+n-m,m) && f(i+m,j,n-m)) for (1<=m<n)
        if (s1 == s2) return true;
        int len = s1.length();
        bool dp[len][len][len+1];
        int i, j, m, n;
        for (i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                dp[i][j][0] = true;
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        
        for (n = 2; n <= len; n++) {
            for (i = 0; i <= len-n; i++) {
                for (j = 0; j <= len-n; j++) {
                    dp[i][j][n] = false;
                    for (m = 1; m < n; m++) {
                        dp[i][j][n] = (dp[i][j][m] && dp[i+m][j+m][n-m]) ||
                                      (dp[i][j+n-m][m] && dp[i+m][j][n-m]);
                        if (dp[i][j][n]) break;
                    }
                }
            }
        }
        
        return dp[0][0][len];
    }


/* Java solution */
public class Solution {
    // let dp[i][j][m] means s1[i:i+m) and s2[j:j+m) is scrambled string
    // so dp[i][j][m] = (dp[i][j][k] && dp[i+k][j+k][m-k]) ||
    //                  (dp[i][j+m-k][k] && dp[i+k][j][m-k])   for (1<=k<m)
    public boolean isScramble(String s1, String s2) {
        int n = s1.length();
        boolean[][][] dp = new boolean[n][n][n+1];
        int i, j, m, k;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j][1] = (s1.charAt(i) == s2.charAt(j));
            }
        }
        for (m = 2; m <= n; m++) {
            for (i = 0; i+m <= n; i++) {
                for (j = 0; j+m <= n; j++) {
                    for (k = 1; k < m; k++) {
                        dp[i][j][m] = ((dp[i][j][k] && dp[i+k][j+k][m-k]) ||
                                       (dp[i][j+m-k][k] && dp[i+k][j][m-k]));
                        if (dp[i][j][m]) break;
                    }
                }
            }
        }
        return dp[0][0][n];
    }
}

