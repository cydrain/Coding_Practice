/*
 * Longest Palindrome

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */
class Solution {
public:
    int longestPalindrome(string s) {
        bitset<52> bs;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                bs.flip(s[i]-'A');
            } else {
                bs.flip(s[i]-'a'+26);
            }
        }
        int odd = bs.count();
        if (odd == 0) return s.length();
        else return (s.length()-odd+1);
    }
};
