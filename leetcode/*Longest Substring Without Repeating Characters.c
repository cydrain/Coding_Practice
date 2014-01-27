/*
 * Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without
 * repeating characters. 
 *
 * For example, the longest substring without repeating letters for
 * "abcabcbb" is "abc", which the length is 3.
 * For "bbbbb" the longest substring is "b", with the length of 1.
 *
 */

    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> exist(256, false);
        int i = 0, j = 0;
        int maxlen = 0;
        while (j < s.length()) {
            if (exist[s[j]]) {
                maxlen = max(maxlen, j-i);
                while (s[i] != s[j]) {
                    exist[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            }
            else {
                exist[s[j]] = true;
                j++;
            }
        }
        maxlen = max(maxlen, j-i);
        return maxlen;
    }




    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> idx(256, -1);
        int maxlen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (idx[s[i]] != -1) {
                start = max(start, idx[s[i]]);
            }
            maxlen = max(maxlen, i-start);
            idx[s[i]] = i;
        }
        return maxlen;
    }
