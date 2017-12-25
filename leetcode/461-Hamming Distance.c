/*
 * Hamming Distance
 *
 * The Hamming distance between two integers is the number of positions at which
 * the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int cnt = 0;
        while (n) {
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        n = (n & 0x55555555) + ((n & 0xAAAAAAAA) >> 1);
        n = (n & 0x33333333) + ((n & 0xCCCCCCCC) >> 2);
        n = (n & 0x0F0F0F0F) + ((n & 0xF0F0F0F0) >> 4);
        n = (n & 0x00FF00FF) + ((n & 0xFF00FF00) >> 8);
        n = (n & 0x0000FFFF) + ((n & 0xFFFF0000) >> 16);
        return n;
    }
};
