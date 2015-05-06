/*
 * Palindrome Partitioning II
 *
 * Given a string s, partition s such that every substring of the partition
 * is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced
 * using 1 cut. 
 *
 */

/* C solution */
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length();
        if (n <= 1) return 0;
        vector<vector<bool> > palin(n, vector<bool>(n, false));
        vector<int> dp(n+1, 0);
        int i, j;
        for (i = 0; i <= n; i++) {
            dp[i] = n-i-1;
        }
        for (i = n-1; i >= 0; i--) {
            for (j = i; j < n; j++) {
                if (s[i] == s[j] && ((j-i) < 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0];
    }



    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // suppose s[i:j] is palindrome, then mincut(j) = min{mincut(i-1)+1} 
        int len = s.length();
        vector<vector<bool>> palin(len, vector<bool>(len, false));
        vector<int> cut(len+1, 0);
        int i, j;
        
        for (i = 0; i <= len; i++) {
            cut[i] = i-1;
        }
        for (j = 0; j < len; j++) {
            for (i = j; i >= 0; i--) {
                if (s[i] == s[j] && (j-i < 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                    cut[j+1] = min(cut[j+1], cut[i]+1);
                }
            }
        }
        return cut[len];
    }


/* Java solution */
public class Solution {
    // let cut[i] stores the min cut needed for s[0:i]
    // if s[i:j] is palindrome, cut[j] = min(cut[j], 1+cut[i-1])
    public int minCut(String s) {
        int n = s.length();
        boolean[][] isPalin = new boolean[n][n];
        int[] cut = new int[n];
        int i, j;
        for (i = 0; i < n; i++) {
            cut[i] = i;
        }
        for (j = 0; j < n; j++) {
            for (i = 0; i <= j; i++) {
                if (s.charAt(i) == s.charAt(j) &&
                    (j-i < 2 || isPalin[i+1][j-1])) {
                    isPalin[i][j] = true;
                    if (i == 0) {
                        cut[j] = 0;
                    } else {
                        cut[j] = Math.min(cut[j], 1+cut[i-1]);
                    }
                }
            }
        }
        return cut[n-1];
    }
}

