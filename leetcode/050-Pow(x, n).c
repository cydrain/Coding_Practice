/*
 * Pow(x,n)
 *
 * Implement pow(x, n). 
 *
 */

/* C solution */
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1.0;
        double half = pow(x, n/2);
        if (n % 2) {
            if (n > 0) {
                return half * half * x;
            }
            else {
                return half * half / x;
            }
        }
        else {
            return half * half;
        }
    }


    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned long m = abs((long)n);
        double r = 1.0;
        for ( ; m; x *= x, m >>= 1) {
            if (m & 0x1) {
                r *= x;
            }
        }
        return (n < 0) ? 1/r : r;
    }


/* Java solution */
public class Solution {
    public double pow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        long m = Math.abs((long)n);
        double r = 1.0;
        for ( ; m > 0; x *= x, m >>= 1) {
            if ((m & 0x1) != 0) {
                r *= x;
            }
        }
        return ((n<0) ? 1/r : r);
    }
}

