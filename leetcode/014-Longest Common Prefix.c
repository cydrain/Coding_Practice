/*
 * Longest Common Prefix
 *
 * Write a function to find the longest common prefix string
 * amongst an array of strings. 
 *
 */

/* C solution */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        int i, j;
        
        for (i = 0; i < strs[0].length(); i++) {
            for (j = 1; j < n; j++) {
                if (strs[j].length() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};


/* Java solution */
public class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        if (n == 0) return "";

        int i, j;
        for (i = 0; i < strs[0].length(); i++) {
            for (j = 1; j < n; j++) {
                if (i >= strs[j].length() ||
                    strs[0].charAt(i) != strs[j].charAt(i)) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
}

