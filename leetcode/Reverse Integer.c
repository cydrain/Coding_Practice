/*
 * Reverse Integer
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321 
 *
 */

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
