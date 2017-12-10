/*
 * Valid Palindrome
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good
 * question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid
 * palindrome. 
 *
 */

    bool isValid(const char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    char toLow(const char c) {
        if (c >= 'A' && c <= 'Z') {
            return c-'A'+'a';
        }
        else {
            return c;
        }
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (!isValid(s[l])) {
                l++;
            } else if (!isValid(s[r])) {
                r--;
            } else {
                if (toLow(s[l]) == toLow(s[r])) {
                    l++;
                    r--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }


/* Java solution */
public class Solution {
    public boolean isValidChar(char c) {
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')) {
            return true;
        } else {
            return false;
        }
    }
    public boolean isPalindrome(String s) {
        String ss = s.toLowerCase();
        int n = s.length();
        int i = 0, j = n-1;
        while (i < j) {
            if (!isValidChar(ss.charAt(i))) {
                i++;
            } else if (!isValidChar(ss.charAt(j))) {
                j--;
            } else {
                if (ss.charAt(i) == ss.charAt(j)) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}

