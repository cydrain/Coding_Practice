/*
 * Add Bold Tag in String
 *
 * Given a string s and a list of strings dict, you need to add a closed pair of
 * bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two
 * such substrings overlap, you need to wrap them together by only one pair of 
 * closed bold tag. Also, if two substrings wrapped by bold tags are consecutive,
 * you need to combine them.
 *
 * Example 1:
 * Input: 
 *   s = "abcxyz123"
 *   dict = ["abc","123"]
 * Output: "<b>abc</b>xyz<b>123</b>"
 *
 * Example 2:
 * Input: 
 *   s = "aaabbcc"
 *   dict = ["aaa","aab","bc"]
 * Output: "<b>aaabbc</b>c"
 */
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int len = s.length(), dlen;
        if (len == 0) return s;
        bitset<1000> bold;
        int start, idx, i, j;
        string res;
        for (auto d : dict) {
            dlen = d.length();
            for (i = 0; i <= len-dlen; i++) {
                if (s.substr(i,dlen) == d) {
                    for (j = 0; j < dlen; j++) {
                        bold.set(i+j);
                    }
                }
            }
        }
        if (!bold.any()) return s;
        i = 0;
        while (i < len) {
            if (bold.test(i)) {
                res = res + "<b>";
                while (i < len && bold.test(i)) {
                    res = res + s[i++];
                }
                res = res + "</b>";
            } else {
                res = res + s[i++];
            }
        }
        return res;
    }
};
