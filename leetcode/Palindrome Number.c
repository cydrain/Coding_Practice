/*
 * Palindrome Number
 *
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 *
 */

    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int factor = 1;
        int l, r;
        while (x/factor >= 10) {
            factor *= 10;
        }
        while (x >= 10) {
            l = x / factor;
            r = x % 10;
            if (l != r) return false;
            x = x % factor / 10;
            factor /= 100;
        }
        return true;
    }


    bool isPalindrome(int x) {
        if (x < 0) return false;
        int x1 = x, y = 0;
        
        while (x) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        
        return (x1 == y);
    }



// iteration solution
    bool isPalindrome(int x, int &y) {
        if (x == 0) return true;
        if (isPalindrome(x/10, y) && (x%10 == y%10)) {
            y /= 10;
            return true;
        }
        else {
            return false;
        }
    }
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        return isPalindrome(x, x);
    }
