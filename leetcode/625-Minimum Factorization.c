/*
 * Minimum Factorization
 *
 * Given a positive integer a, find the smallest positive integer b whose
 * multiplication of each digit equals to a.
 *
 * If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.
 *
 * Example 1
 *  Input: 48 
 *  Output: 68
 *
 * Example 2
 *  Input: 15
 *  Output: 35
 */
class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) return a;
        long num = 0, base = 1;
        for (int i = 9; i > 1; i--) {
            while (a % i == 0) {
                a /= i;
                num = base * i + num;
                base *= 10;
            }
        }
        if (a != 1 || num > INT_MAX) return 0;
        return num;
    }
};
