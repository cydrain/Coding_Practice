/*
 * Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', find the
 * length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which
 * has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses
 * substring is "()()", which has length = 4. 
 *
 */

    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> stk;
        int start = -1, maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                if (stk.empty()) {
                    start = i;
                }
                else {
                    stk.pop();
                    if (stk.empty()) {
                        maxlen = max(maxlen, i-start);
                    }
                    else {
                        maxlen = max(maxlen, i-stk.top());
                    }
                }
            }
        }
        return maxlen;
    }
