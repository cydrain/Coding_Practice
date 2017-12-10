/*
 * Excel Sheet Column Title
 *
 * Given a positive integer, return its corresponding column title as appear
 * in an Excel sheet.
 *
 * For example:
 *
 *    1 -> A
 *    2 -> B
 *    3 -> C
 *    ...
 *    26 -> Z
 *    27 -> AA
 *    28 -> AB 
 */

/* C solution */
class Solution {
public:
    string convertToTitle(int n) {
        string r;
        char c;
        while (--n >= 0) {
            c = n%26 + 'A';
            r = c + r;
            n /= 26;
        }
        return r;
    }
};

