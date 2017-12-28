/*
 * Longest Word in Dictionary through Deleting
 *
 * Given a string and a string dictionary, find the longest string in the dictionary
 * that can be formed by deleting some characters of the given string. If there are
 * more than one possible results, return the longest word with the smallest 
 * lexicographical order. If there is no possible result, return the empty string.
 *
 * Example 1:
 *
 * Input:
 *   s = "abpcplea", d = ["ale","apple","monkey","plea"]
 *
 * Output: 
 *   "apple"
 */
class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        int slen = s.length(), wlen;
        int i, j;
        string res;
        for (auto word : dict) {
            wlen = word.length();
            if (slen < wlen) continue;
            i = 0, j = 0;
            while (i < slen && j < wlen) {
                if (s[i] == word[j]) i++, j++;
                else i++;
            }
            if (j == wlen && (res.length() < wlen || (res.length() == wlen && res > word))) {
                res = word;
            }
        }
        return res;
    }
};
