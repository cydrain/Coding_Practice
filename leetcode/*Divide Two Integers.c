/*
 * Divide Two Integers
 *
 * Divide two integers without using multiplication,
 * division and mod operator. 
 *
 */

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
