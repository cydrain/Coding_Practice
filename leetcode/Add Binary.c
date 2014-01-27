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
