/*
 * Valid Word Abbreviation
 *
 * Given a non-empty string s and an abbreviation abbr, return whether the string
 * matches with the given abbreviation.
 *
 * A string such as "word" contains only the following valid abbreviations:
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1",
 *  "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 *
 * Notice that only the above abbreviations are valid abbreviations of the string
 * "word". Any other string is not a valid abbreviation of "word".
 *
 * Note:
 * Assume s contains only lowercase letters and abbr contains only lowercase
 * letters and digits.
 *
 * Example 1:
 *   Given s = "internationalization", abbr = "i12iz4n":
 *   Return true.
 */
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int len1 = word.length();
        int len2 = abbr.length();
        int i = 0, j = 0, num = 0;
        while (i < len1 && j < len2) {
            if (abbr[j] >= '0' && abbr[j] <= '9') {
                if (num == 0 && abbr[j] == '0') return false;
                num = num*10 + (abbr[j]-'0');
                j++;
            } else if (num > 0) {
                i += num;
                num = 0;
            } else if (word[i] == abbr[j]) {
                i++, j++;
            } else {
                return false;
            }
        }
        return (i+num == len1 && j == len2);
    }
};
