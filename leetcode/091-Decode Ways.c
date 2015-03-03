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

/* C solution */
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        int n = s.length();
        int i, num1, num2;
        string ss = "0"+s;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (i = 2; i <= n; i++) {
            num1 = ss[i] - '0';
            num2 = (ss[i-1]-'0')*10 + num1;
            if (num1 > 0) dp[i] += dp[i-1];
            if (num2 >= 10 && num2 <= 26) dp[i] += dp[i-2];
            if (dp[i] == 0) return 0;
        }
        return dp[n];
    }
};


/* Java solution */
public class Solution {
    public int numDecodings(String s) {
        if (s.equals("") || s.charAt(0) == '0') return 0;
        int n = s.length();
        String ss = "0" + s;
        int i, n1, n2;
        int[] dp = new int[n+1];
        dp[0] = 1;
        for (i = 1; i <= n; i++) {
            n1 = ss.charAt(i) - '0';
            n2 = (ss.charAt(i-1)-'0')*10 + n1;
            if (n1 > 0) {
                dp[i] += dp[i-1];
            }
            if (n2 >= 10 && n2 <= 26) {
                dp[i] += dp[i-2];
            }
            if (dp[i] == 0) {
                return 0;
            }
        }
        return dp[n];
    }
}

