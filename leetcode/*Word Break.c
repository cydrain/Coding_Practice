// Word Break
// Given a string s and a dictionary of words dict, determine if s can be
// segmented into a space-separated sequence of one or more dictionary words.
//
// For example, given
// s = "leetcode",
// dict = ["leet", "code"]. 
// Return true because "leetcode" can be segmented as "leet code". 
//
    // let f[i][j] means whether s[i:j] can be segmented into dict words
    // so f[i][j] != f[i][n-1] if s[n:j] is in dict words 
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        string ss = "#" + s;
        vector<bool> dp(n+1, false);
        int i, j;
        dp[0] = true;
        for (j = 1; j <= n; j++) {
            for (i = 1; i <= j; i++) {
                if (dp[j]) continue;
                if (dict.find(ss.substr(i, j-i+1)) != dict.end()) {
                    dp[j] = dp[i-1];
                }
            }
        }
        return dp[n];
    }


    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        // let dp[i][j] = true means, s[i:j] can be break into words in dict
        // so dp[i][j] = true if s[i:j] is in dict or
        // dp[i][k] == true && dp[k+1][j] == true (i<k<j)
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int i, j, k;
        for (i = 0; i < n; i++) {   // i is the length of the substr
            for (j = 0; j+i < n; j++) { // j is the start index of the substr
                if (dict.find(s.substr(j,i+1)) != dict.end()) {
                    dp[j][j+i] = true;
                }
                else {
                    for (k = j; k < j+i; k++) {
                        if (dp[j][k] && dp[k+1][j+i]) {
                            dp[j][j+i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }

