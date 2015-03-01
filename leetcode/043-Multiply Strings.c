/*
 * Multiply Strings
 *
 * Given two numbers represented as strings, return multiplication
 * of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 */

/* C solution */
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1 == "0" || num2 == "0") return "0";
        int len1 = num1.length();
        int len2 = num2.length();
        int v1, v2, sum, carry = 0;
        string r(len1+len2, '0');
        
        for (int i = len1-1; i >= 0; i--) {
            v1 = num1[i] - '0';
            carry = 0;
            for (int j = len2-1; j >= 0; j--) {
                v2 = num2[j] - '0';
                sum = v1 * v2 + carry + (r[i+j+1] - '0');
                carry = sum / 10;
                sum = sum % 10;
                r[i+j+1] = sum + '0';
            }
            r[i] = carry + '0';
        }
        
        if (r[0] == '0') {
            return r.substr(1, len1+len2-1);
        }
        else {
            return r;
        }
    }


/* Java solution */
public class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        int len1 = num1.length();
        int len2 = num2.length();
        StringBuilder r = new StringBuilder();
        int i, j, carry, sum;
        
        for (i = 0; i < len1+len2; i++) {
            r.append('0');
        }
        
        for (i = len1-1; i >= 0; i--) {
            carry = 0;
            for (j = len2-1; j >= 0; j--) {
                sum = (num1.charAt(i)-'0')*(num2.charAt(j)-'0') + (r.charAt(i+j+1)-'0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                r.setCharAt(i+j+1, (char)(sum+'0'));
            }
            r.setCharAt(i, (char)(carry+'0'));
        }
        
        if (r.charAt(0) == '0') {
            return r.substring(1);
        } else {
            return r.toString();
        }
    }
}

