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




    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> target(256, 0);
        vector<int> src(256, 0);
        int begin, end;
        int n = T.size(), count = 0;
        int minLen = INT_MAX, idx;
        
        for (int i = 0; i < n; i++) {
            target[T[i]]++;
        }
        for (begin = 0, end = 0; end < S.size(); end++) {
            if (target[S[end]] == 0) continue;

            src[S[end]]++;
            if (src[S[end]] <= target[S[end]]) count++;
            
            if (count == n) {
                while (target[S[begin]] == 0 || src[S[begin]] > target[S[begin]]) {
                    if (src[S[begin]] > target[S[begin]]) {
                        src[S[begin]]--;
                    }
                    begin++;
                }
                if (minLen > (end-begin+1)) {
                    minLen = end-begin+1;
                    idx = begin;
                }
            }
        }
        
        if (minLen == INT_MAX) {
            return string("");
        }
        else {
            return S.substr(idx, minLen);
        }
    }
