/*
 * Add Strings
 *
 * Given two non-negative integers num1 and num2 represented as string,
 * return the sum of num1 and num2.
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0") return num2;
        if (num2 == "0") return num1;
        int len1 = num1.length(), len2 = num2.length();
        int i, j, v1, v2, sum, carry = 0;
        string ans;
        i = len1-1, j = len2-1;
        while (i >= 0 || j >= 0 || carry) {
            v1 = (i >= 0) ? num1[i--]-'0' : 0;
            v2 = (j >= 0) ? num2[j--]-'0' : 0;
            sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = to_string(sum) + ans;
        }
        return ans;
    }
};
