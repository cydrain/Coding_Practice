/*
 * Interleaving String
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 *  Given:
 *   s1 = "aabcc",
 *   s2 = "dbbca",
 *
 *  When s3 = "aadbbcbcac", return true.
 *  When s3 = "aadbbbaccc", return false. 
 *
 */

// iterative solution, cannot pass the large test
    bool isInterleave(string s1, int idx1, string s2, int idx2, string s3, int idx3) {
        if ((idx1 == s1.size()) && (idx2 == s2.size()) && (idx3 == s3.size())) {
            return true;
        }
        
        if (s3[idx3] == s1[idx1] && s3[idx3] == s2[idx2]) {
            return (isInterleave(s1, idx1+1, s2, idx2, s3, idx3+1) ||
                    isInterleave(s1, idx1, s2, idx2+1, s3, idx3+1));
        }
        else if (s3[idx3] == s1[idx1]) {
            return isInterleave(s1, idx1+1, s2, idx2, s3, idx3+1);
        }
        else if (s3[idx3] == s2[idx2]) {
            return isInterleave(s1, idx1, s2, idx2+1, s3, idx3+1);
        }
        else {
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        if (s1 == "") return (s2 == s3);
        if (s2 == "") return (s1 == s3);
        if (s1.size() + s2.size() != s3.size()) return false;
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }



// DP solution
bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function    
    // let s1[1:n1], s2[1:n2], s2[1:n3]
    // suppose f(i,j) = true means, s1[1:i] and s2[1:j] can get s3[1:i+j]
    // so f(i,j) = true if f(i-1,j) == true and s1[i] == s3[i+j]
    //                  or f(i,j-1) == true and s2[j] == s3[i+j]
    
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    if (len1+len2 != len3) return false;
    
    string ss1 = "#" + s1;
    string ss2 = "#" + s2;
    string ss3 = "#" + s3;
    vector<vector<bool> > dp(len1+1, vector<bool>(len2+1, false));
    int i, j;
    
    dp[0][0] = true;
    for (i = 1; i <= len1; i++) {
        if (ss1[i] == ss3[i] && dp[i-1][0])
            dp[i][0] = true; 
    }
    for (j = 1; j <= len2; j++) {
        if (ss2[j] == ss3[j] && dp[0][j-1])
            dp[0][j] = true;
    }
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            dp[i][j] = (ss1[i] == ss3[i+j] && dp[i-1][j]) ||
                       (ss2[j] == ss3[i+j] && dp[i][j-1]);
        }
    }
    return dp[len1][len2];
}




    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        // let s1,s2,s3 's index start from 1
        // suppose f(i,j) = true means, s1[1:i] and s2[1:j] can form s3[1:i+j]
        // then f(i,j) = (s1[i] == s3[i+j] && f(i-1,j)) ||
        //               (s2[j] == s3[i+j] && f(i,j-1))
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1+len2 != len3) return false;
        vector<bool> dp(len2+1, false);
        string ss1 = "#" + s1;
        string ss2 = "#" + s2;
        string ss3 = "#" + s3;
        int i, j;
        dp[0] = true;
        for (i = 0; i <= len1; i++) {
            dp[0] = dp[0] && (ss1[i] == ss3[i]);
            for (j = 1; j <= len2; j++) {
                dp[j] = (ss1[i] == ss3[i+j] && dp[j]) ||
                        (ss2[j] == ss3[i+j] && dp[j-1]);
            }
        }
        return dp[len2];
    }


/* Java solution */
public class Solution {
    // let dp[i][j] means whether ss1[1:i] and ss2[1:j] can form ss3[1:i+j]
    // so if (ss1[i] == ss3[i+j]), dp[i][j] = dp[i-1][j];
    //    if (ss2[j] == ss3[i+j]), dp[i][j] = pd[i][j-1].
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3) return false;
        String ss1 = "#" + s1;
        String ss2 = "#" + s2;
        String ss3 = "#" + s3;
        boolean[][] dp = new boolean[len1+1][len2+1];
        int i, j;
        
        dp[0][0] = true;
        for (i = 1; i <= len1; i++) {
            dp[i][0] = (ss1.charAt(i) == ss3.charAt(i) ? dp[i-1][0] : false);
        }
        for (j = 1; j <= len2; j++) {
            dp[0][j] = (ss2.charAt(j) == ss3.charAt(j) ? dp[0][j-1] : false);
        }
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                dp[i][j] = ((ss1.charAt(i) == ss3.charAt(i+j) && dp[i-1][j]) ||
                            (ss2.charAt(j) == ss3.charAt(i+j) && dp[i][j-1]));
            }
        }
        return dp[len1][len2];
    }
}

