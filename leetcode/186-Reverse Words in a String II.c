/*
 * Reverse Words in a String II
 *
 * Given an input string, reverse the string word by word. A word is defined as
 * a sequence of non-space characters.
 *
 * The input string does not contain leading or trailing spaces and the words
 * are always separated by a single space.
 *
 * For example,
 *   Given s = "the sky is blue",
 *   return "blue is sky the". 
 */
class Solution {
public:
    void reverseWords(vector<char>& str) {
        int n = str.size();
        int i, j;
        reverse(str.begin(), str.end());
        for (i = 0; i < n; i = j+1) {
            for (j = i+1; j < n && str[j] != ' '; j++);
            reverse(str.begin()+i, str.begin()+j);
        }
    }
};
