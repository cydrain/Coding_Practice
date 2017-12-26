/*
 * Strobogrammatic Number
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Write a function to determine if a number is strobogrammatic. The number
 * is represented as a string.
 *
 * For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */
class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char> m = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        int i, j, len = num.length();
        for (i = 0, j = len-1; i <= j; i++, j--) {
            if ((m.find(num[i]) == m.end()) || (m[num[i]] != num[j]))
                return false;
        }
        return true;
    }
};
