/*
 * Decode Ways
 *
 * A message containing letters from A-Z is being encoded to numbers
 * using the following mapping:
 *
 *  'A' -> 1
 *  'B' -> 2
 *  ...
 *  'Z' -> 26
 *
 * Given an encoded message containing digits, determine the total number
 * of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2. 
 *
 */

int numDecodings(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len = s.size();
    string S = "#" + s;
    vector<int> dp(len+1, 0);
    int num1, num2;

    if (len == 0 || s[0] == '0') return 0;
    if (len == 1) return 1;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= len; i++) {
        num1 = S[i] - '0';
        num2 = (S[i-1] - '0') * 10 + num1;
        if (num1 > 0) {
            if (num2 >= 10 && num2 <= 26) {
                dp[i] = dp[i-2] + dp[i-1];
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        else {  // (num1 == 0)
            if (num2 == 0) {
                return 0;
            }
            else if (num2 >= 10 && num2 <= 26) {
                dp[i] = dp[i-2];
            }
            else {
                return 0;
            }
        }
    }
    return dp[len];
}
