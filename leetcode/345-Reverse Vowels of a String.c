/*
 * Reverse Vowels of a String
 *
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 *   Given s = "hello", return "holle".
 *
 * Example 2:
 *   Given s = "leetcode", return "leotcede". 
 */
class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s) {
        int len = s.length();
        int l = 0, r = len-1;
        while (l < r) {
            if (!isVowel(s[l])) {
                l++;
            } else if (!isVowel(s[r])) {
                r--;
            } else {
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};
