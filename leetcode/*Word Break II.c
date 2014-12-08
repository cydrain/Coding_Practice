/* 
 * Word Break II
 *
 * Given a string s and a dictionary of words dict, add spaces in s to
 * construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"]. 
 */

    // we should search the valid solution from back to front
    void wordBreakHelper(string &s, int end, vector<vector<bool>> &inDict,
                         vector<string> &path, vector<string> &res) {
        int n = s.length();
        string t;
        int i;
        if (end == -1) {
            for (i = path.size()-1; i >= 0; i--) {
                if (i != path.size()-1) {
                    t += " ";
                }
                t += path[i];
            }
            res.push_back(t);
            return;
        }
        for (i = 0; i <= end; i++) {
            if (inDict[i][end]) {
                t = s.substr(i, end-i+1);
                path.push_back(t);
                wordBreakHelper(s, i-1, inDict, path, res);
                path.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        string t;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int i, j;
        
        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                t = s.substr(i, j-i+1);
                if (dict.find(t) != dict.end()) {
                    dp[i][j] = true;
                }
            }
        }
        
        vector<string> res;
        vector<string> path;
        wordBreakHelper(s, n-1, dp, path, res);
        return res;
    }

