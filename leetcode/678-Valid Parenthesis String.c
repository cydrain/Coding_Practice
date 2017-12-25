/* 
 * Valid Parenthesis String
 *
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid.
 * We define the validity of a string by these rules:
 *
 *  Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 *  Any right parenthesis ')' must have a corresponding left parenthesis '('.
 *  Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 *  '*' could be treated as a single right parenthesis ')' or a single left
 *  parenthesis '(' or an empty string.
 *  An empty string is also valid.
 */
class Solution {
public:
    bool checkValidString(string s) {
        int len = s.length();
        int i, lower = 0, upper = 0;
        for (auto c : s) {
            if (c == '(') {
                lower++;
                upper++;
            } else if (c == ')') {
                if (lower > 0) lower--;
                upper--;
            } else {
                if (lower > 0) lower--;
                upper++;
            }
            if (upper < 0) return false;
        }
        return (lower == 0);
    }
};
