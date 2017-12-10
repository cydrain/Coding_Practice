/*
 * Length of Last Word
 *
 * Given a string s consists of upper/lower-case alphabets and empty
 * space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5. 
 *
 */

    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0, len = 0;
        while (*s) {
            if (*s != ' ') {
                count++;
                len = count;
            }
            else {
                count = 0;
            }
            s++;
        }
        
        return len;
    }



    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, len = 0;
        bool restart = true;
        char c;
        while (c = *(s+i)) {
            if (c != ' ') {
                if (restart) {
                    len = 1;
                    restart = false;
                }
                else {
                    len++;
                }
            }
            else {
                restart = true;
            }
            i++;
        }
        
        return len;
    }


/* Java solution */
public class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int i, count = 0, last = 0;
        for (i = 0; i < n; i++) {
            if (s.charAt(i) == ' ') {
                count = 0;
            } else {
                count++;
                last = count;
            }
        }
        return last;
    }
}

