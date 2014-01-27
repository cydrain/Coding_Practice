/*
 * Plus One
 *
 * Given a number represented as an array of digits, plus one to the number.
 *
 */

    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1, 1);
        return digits;
    }
