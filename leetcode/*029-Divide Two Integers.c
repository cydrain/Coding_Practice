/*
 * Divide Two Integers
 *
 * Divide two integers without using multiplication,
 * division and mod operator. 
 *
 */

/* C solution */
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
        int r = 0, i = 0;
        while (m >= (n<<i)) {
            i++;
        }
        while (i--) {
            if (m >= (n<<i)) {
                m -= n<<i;
                r += 1<<i;
            }
        }
        return ((dividend ^ divisor) >> 31) ? -r : r;
    }


/* Java solution */
public class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        boolean neg = ((dividend > 0 && divisor < 0) ||
                       (dividend < 0 && divisor > 0));
        long m = Math.abs((long)dividend);
        long n = Math.abs((long)divisor);
        long r = 0;
        int i = 0;
        
        while (m >= (n<<i)) {
            i++;
        }
        while (m >= n && --i >= 0) {
            if (m >= (n<<i)) {
                m -= (n<<i);
                r += (1L<<i);
            }
        }
        if (neg) {
            r = -r;
        }
        if (r >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (r <= Integer.MIN_VALUE) return Integer.MIN_VALUE;
        return (int)r;
    }
}

