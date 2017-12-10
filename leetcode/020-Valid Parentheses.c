/*
 * Valid Parentheses
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not.
 *
 */

/* C solution */
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[':
                    stk.push(s[i]);
                    break;
                case ')':
                    if (!stk.empty() && stk.top() == '(') {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case '}':
                    if (!stk.empty() && stk.top() == '{') {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if (!stk.empty() && stk.top() == '[') {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return stk.empty();
    }


/* Java solution */
public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        int i;
        
        for (i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '(':
                case '[':
                case '{':
                    stk.push(s.charAt(i));
                    break;
                case ')':
                    if (!stk.empty() && stk.peek() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!stk.empty() && stk.peek() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!stk.empty() && stk.peek() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        
        return stk.empty();
    }
}

