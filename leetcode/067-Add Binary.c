/*
 * Add Binary
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 *  a = "11"
 *  b = "1"
 * Return "100". 
 *
 */

    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = a.length()-1, j = b.length()-1;
        int va, vb;
        int sum, carry = 0;
        string r;
        
        while (i >= 0 || j >= 0 || carry) {
            va = (i >= 0) ? a[i--]-'0' : 0;
            vb = (j >= 0) ? b[j--]-'0' : 0;
            sum = va + vb + carry;
            carry = sum / 2;
            sum = sum % 2;
            r.insert(0, 1, sum+'0');
        }
        
        return r;
    }


/* Java solution */
public class Solution {
    public String addBinary(String a, String b) {
        if (a.equals("0")) return b;
        if (b.equals("0")) return a;
        int len_a = a.length();
        int len_b = b.length();
        StringBuilder r = new StringBuilder();
        int len_r = 1 + Math.max(len_a, len_b);
        int sum, carry = 0, i;
        int v1, v2;
        
        for (i = 0; i < len_r; i++) {
            r.append('0');
        }
        while (len_a > 0 || len_b > 0 || carry > 0) {
            v1 = (len_a > 0) ? a.charAt(len_a-1)-'0' : 0;
            v2 = (len_b > 0) ? b.charAt(len_b-1)-'0' : 0;
            sum = v1 + v2 + carry;
            carry = sum / 2;
            sum = sum % 2;
            r.setCharAt(len_r-1, (char)(sum+'0'));
            len_r--;
            if (len_a > 0) len_a--;
            if (len_b > 0) len_b--;
        }
        
        if (r.charAt(0) == '0') {
            return r.substring(1);
        } else {
            return r.toString();
        }
    }
}

