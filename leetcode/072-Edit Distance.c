/*
 * Edit Distance
 *
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *  a) Insert a character
 *  b) Delete a character
 *  c) Replace a character
 *
 */

/* C solution */
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // let w1, w2 start from index 1
        // suppose f(i,j) means the minimum steps required to convert w1[1:i] to w2[1:j]
        // if w1[i] != w2[j], then f(i,j) = 1 + min{f(i-1,j), f(i,j-1), f(i-1,j-1)}
        // if w1[i] == w2[j], then f(i,j) = min{f(i-1,j)+1, f(i,j-1)+1, f(i-1,j-1)}
        int len1 = word1.length();
        int len2 = word2.length();
        string w1 = "#" + word1;
        string w2 = "#" + word2;
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));
        int i, j;
        for (i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (j = 1; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                if (w1[i] == w2[j]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return dp[len1][len2];
    }


/* Java solution */
public class Solution {
    // if s1[i] == s2[j], dp[i][j] = min{dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1}
    // if s1[i] != s2[j], dp[i][j] = min{dp[i-1][j-1], dp[i-1][j], dp[i][j-1]} + 1
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        String s1 = "#" + word1;
        String s2 = "#" + word2;
        int[][] dp = new int[len1+1][len2+1];
        int i, j;
        for (i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (j = 1; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + 1;
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return dp[len1][len2];
    }
}

