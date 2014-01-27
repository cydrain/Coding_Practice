/*
 * Sqrt(x)
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 *
 */

    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x <= 1) return x;
        int r = 0, n = 1, tmp;
        while (n <= x/n) {
            n = n << 1;
        }
        n = n >> 1;
        while (n) {
            tmp = r + n;
            if (tmp == x/tmp) return tmp;
            if (tmp < x/tmp) {
                r = tmp;
            }
            n = n >> 1;
        }
        return r;
    }



    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x <= 1) return x;
        int l = 1, r = x, m;
        while (r - l > 1) {
            m = l + (r - l) / 2;
            if (m == x/m) return m;
            if (m < x/m) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return l;
    }
