/* 
 * Excel Sheet Column Number
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *   A -> 1
 *   B -> 2
 *   C -> 3
 *   ...
 *   Z -> 26
 *   AA -> 27
 *   AB -> 28 
 */

/* C solution */
class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int i, r = 0;
        for (i = 0; i < n; i++) {
            r = r*26 + (s[i]-'A'+1);
        }
        return r;
    }
};

