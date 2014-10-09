/*
 * Longest Common Prefix
 *
 * Write a function to find the longest common prefix string
 * amongst an array of strings. 
 *
 */

    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        int n = strs.size();
        int len = strs[0].length();
        int i, j;
        for (i = 0; i < len; i++) {
            for (j = 1; j < n; j++) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }

