/*
 * Monotone Increasing Digits
 *
 * Given a non-negative integer N, find the largest number that is less than or
 * equal to N with monotone increasing digits.
 *
 * (Recall that an integer has monotone increasing digits if and only if each pair
 * of adjacent digits x and y satisfy x <= y.)
 *
 * Example 1:
 *   Input: N = 10
 *   Output: 9
 * Example 2:
 *   Input: N = 1234
 *   Output: 1234
 * Example 3:
 *   Input: N = 332
 *   Output: 299
 */
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i, mark = s.length();
        for (i = s.length()-1; i > 0; i--) {
            if (s[i] < s[i-1]) {
                mark = i;
                s[i-1] = s[i-1] - 1;
            }
        }
        for (i = mark; i < s.length(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
