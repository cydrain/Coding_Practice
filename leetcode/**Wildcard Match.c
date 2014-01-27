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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*s == '\0' && *p == '\0') return true;
        const char *start_s = NULL, *start_p = NULL;
        while (*s != '\0') {
            if (*p == *s || *p == '?') {
                s++, p++;
            }
            else if (*p == '*') {
                while (*p == '*') p++;
                if (*p == '\0') return true;
                start_s = s;
                start_p = p;
            }
            // when mis-match found and there is '*' meet before, go back
            else if (start_s != '\0') {
                p = start_p;
                s = ++start_s;
            }
            else {
                return false;
            }
        }
        
        // when *s is empty, *p should be empty or all '*'
        while (*p == '*') p++;

        return (*p == '\0');
    }

