/*
 * Factorial Trailing Zeroes
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */

/* C solutions */
class Solution {
public:
    int trailingZeroes(int n) {
        return (n == 0 ? 0 : trailingZeroes(n/5) + n/5);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int r = 0;
        while (n) {
            r += n/5;
            n /= 5;
        }
        return r;
    }
};

