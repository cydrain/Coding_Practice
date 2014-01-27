/*
 * Distinct Subsequences
 *
 * Given a string S and a string T, count the number of distinct
 * subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from
 * the original string by deleting some (can be none) of the
 * characters without disturbing the relative positions of the
 * remaining characters. (ie, "ACE" is a subsequence of "ABCDE"
 * while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3. 
 *
 */

    // general solution, cannot pass Large testing.
    void numDistinct(string &S, int start, string &T, int idx, int &count) {
        if (idx == T.size()) {
            count++;
            return;
        }
        for (int i = start; i < S.size(); i++) {
            if (S[i] == T[idx]) {
                numDistinct(S, i+1, T, idx+1, count);
            }
        }
    }
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0;
        numDistinct(S, 0, T, 0, count);
        return count;
    }



DP solution:
    // let f(i,j) means the count of distinct subsequences of T[j:] in S[i:]
    // then f(i,j) = f(i+1,j) + f(i+1,j+1) when S[i]==T[j]
    //      f(i,j) = f(i+1,j) when s[i]!=T[j]
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size();
        int n = T.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (S[i] == T[j]) {
                    dp[j] += dp[j+1];
                }
            }
        }
        return dp[0];
    }



    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // suppose S[1:m] and T[1:n]
        // let f(i,j) means the num of distinct subsequences of T[1:j] in S[1:i]
        // if S[i] == T[j], then f(i,j) = f(i-1,j) + f(i-1,j-1)
        // if S[i] != T[j], then f(i,j) = f(i-1,j)
        int m = S.length();
        int n = T.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        string ss = "#" + S;
        string tt = "#" + T;
        int i, j;
        for (i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (ss[i] == tt[j]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
