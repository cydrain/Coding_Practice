/*
 * Wildcard Matching
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 *  bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 *  isMatch("aa","a") → false
 *  isMatch("aa","aa") → true
 *  isMatch("aaa","aa") → false
 *  isMatch("aa", "*") → true
 *  isMatch("aa", "a*") → true
 *  isMatch("ab", "?*") → true
 *  isMatch("aab", "c*a*b") → false
 *
 */

/* C solution */
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*p == '*') {    //return true;
            while(*p == '*') ++p;
            if (*p == '\0') return true;
            while(*s != '\0' && !isMatch(s,p)){
                ++s;                
            }
            return (*s != '\0');
        }
        else if (*p == '\0' || *s == '\0') return *p == *s;
        else if (*p == *s || *p == '?') return isMatch(++s,++p);
        else return false;
    }



    bool isMatch(const char *s, const char *p) {
        const char *s_start = NULL, *p_start = NULL;
        while (*s) {
            if (*s == *p || *p == '?') {
                s++, p++;
            }
            else if (*p == '*') {
                s_start = s;
                p_start = p++;
            }
            else if (s_start != NULL) {
                s = ++s_start;
                p = p_start;
            }
            else {
                return false;
            }
        }
        while (*p == '*') p++;
        return (*p == '\0');
    }



/* Java solution */
public class Solution {
    public boolean isMatch(String s, String p) {
        s = s + '\0';
        p = p + '\0';
        int s_len = s.length(), p_len = p.length();
        int s_start = -1, p_start = -1;
        int i = 0, j = 0;
        while (s.charAt(i) != '\0') {
            if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') {
                i++;
                j++;
            } else if (p.charAt(j) == '*') {
                s_start = i;
                p_start = j++;
            } else if (s_start != -1) {
                i = ++s_start;
                j = p_start;
            } else {
                return false;
            }
        }
        while (j < p_len && p.charAt(j) == '*') j++;
        return (p.charAt(j) == '\0');
    }
}

