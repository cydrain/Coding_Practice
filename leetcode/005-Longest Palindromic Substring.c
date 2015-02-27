/*
 * Longest Palindromic Substring
 *
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, and there
 * exists one unique longest palindromic substring.
 *
 */

/* C solution */
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        int i, j;
        int maxlen = 0, idx;
        for (j = 0; j < len; j++) {
            for (i = 0; i <= j; i++) {
                if (s[i] == s[j] && ((j-i < 2) || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (maxlen < j-i+1) {
                        maxlen = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxlen);
    }


// Manacher Algorithm
    string prepare(string s) {
        string r;
        r.push_back('$');
        r.push_back('#');
        for (int i = 0; i < s.length(); i++) {
            r.push_back(s[i]);
            r.push_back('#');
        }
        return r;
    }
    string manacherPalindrome(string s) {
        string ss = prepare(s);
        vector<int> p(ss.length(), 1);
        int C = 1, R = 1;
        int maxlen = 0, idx;
        for (int i = 2; i < ss.length(); i++) {
            p[i] = (i < R) ? min(p[2*C-i], R-i) : 1;
            while (ss[i+p[i]] == ss[i-p[i]]) {
                p[i]++;
            }
            if (maxlen < p[i]) {
                maxlen = p[i];
                idx = i;
            }
            if (R < i + p[i]) {
                C = i;
                R = i + p[i];
            }
        }
        return s.substr((idx-maxlen)/2, maxlen-1);
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return manacherPalindrome(s);
    }


/* Java solution */
public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] isPalin = new boolean[n][n];
        int i, j;
        int maxlen = 1, start = 0;
        
        for (j = 0; j < n; j++) {
            for (i = 0; i <= j; i++) {
                if (s.charAt(i) == s.charAt(j) &&
                    (j-i < 2 || isPalin[i+1][j-1])) {
                    isPalin[i][j] = true;
                    if (maxlen < j-i+1) {
                        maxlen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substring(start, start+maxlen);
    }
}

