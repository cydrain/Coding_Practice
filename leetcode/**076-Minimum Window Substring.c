/*
 * Minimum Window Substring
 *
 * Given a string S and a string T, find the minimum window in S which
 * will contain all the characters in T in complexity O(n).
 *
 * For example,
 *  S = "ADOBECODEBANC"
 *  T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T,
 * return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there
 * will always be only one unique minimum window in S. 
 *
 */

/* C solution */
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen = S.length();
        int tlen = T.length();
        int needToFind[256] = {0};
        int hasFound[256] = {0};
        int i, begin, end;
        int minlen = slen, min_begin = 0;
        int count = 0;
        
        for (i = 0; i < tlen; i++) {
            needToFind[T[i]]++;
        }
        
        for (begin = 0, end = 0; end < slen; end++) {
            // this char is not in T
            if (needToFind[S[end]] == 0) continue;
            
            if (hasFound[S[end]] < needToFind[S[end]]) {
                count++;
            }
            hasFound[S[end]]++;
            
            if (count == tlen) {
                // advance begin idx as far right as possible
                while (needToFind[S[begin]] == 0 || 
                       hasFound[S[begin]] > needToFind[S[begin]]) {
                    if (hasFound[S[begin]] > needToFind[S[begin]]) {
                        hasFound[S[begin]]--;
                    }
                    begin++;
                }
                // update minWindow
                if (minlen > end-begin+1) {
                    minlen = end-begin+1;
                    min_begin = begin;
                }
            }
        }
        
        if (count == tlen) {
            return S.substr(min_begin, minlen);
        }
        else {
            return "";
        }
    }


/* Java solution */
public class Solution {
    public String minWindow(String S, String T) {
        int slen = S.length();
        int tlen = T.length();
        if (slen < tlen) return "";
        int[] target = new int[256];
        int[] found = new int[256];
        int i, start, end, count = 0;
        int index = 0, minlen = slen;
        
        for (i = 0; i < tlen; i++) {
            target[T.charAt(i)]++;
        }
        for (start = 0, end = 0; end < slen; end++) {
            if (target[S.charAt(end)] == 0) continue;
            found[S.charAt(end)]++;
            if (found[S.charAt(end)] <= target[S.charAt(end)]) {
                count++;
            }
            if (count == tlen) {
                while (target[S.charAt(start)] == 0 || found[S.charAt(start)] > target[S.charAt(start)]) {
                    if (found[S.charAt(start)] > target[S.charAt(start)]) {
                        found[S.charAt(start)]--;
                    }
                    start++;
                }
                if (minlen > end-start+1) {
                    minlen = end-start+1;
                    index = start;
                }
            }
        }
        if (count == tlen) {
            return S.substring(index, index+minlen);
        } else {
            return "";
        }
    }
}

