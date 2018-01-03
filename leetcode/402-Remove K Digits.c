/*
 * Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == 0) return num;
        int len = num.length(), i = 0;
        if (k == len) return "0";
        stack<char> stk;
        string ans;
        for (i = 0; i < len; i++) {
            while (!stk.empty() && stk.top() > num[i] && k-- > 0) {
                stk.pop();
            }
            stk.push(num[i]);
        }
        while (k-- > 0) stk.pop();
        while (!stk.empty()) {
            ans = string(1, stk.top()) + ans;
            stk.pop();
        }
        while (ans.length() > 1 && ans[0] == '0') {
            ans.erase(0,1);
        }
        return ans;
    }
};
