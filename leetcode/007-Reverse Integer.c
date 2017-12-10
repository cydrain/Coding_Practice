/*
 * Reverse Integer
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321 
 *
 */

/* C solution */
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0;
        while (x) {
            r = r*10 + x%10;
            x /= 10;
        }
        return r;
    }


/* Java solution */
public class Solution {
    public int reverse(int x) {
        if (x == 0) return x;
        boolean neg = (x < 0);
        if (neg) x = -x;
        long r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            if ((neg && -r < Integer.MIN_VALUE) ||
                (!neg && r > Integer.MAX_VALUE)) {
                return 0;
            }
            x = x / 10;
        }
        return (neg ? (int)(-r) : (int)r);
    }
}

