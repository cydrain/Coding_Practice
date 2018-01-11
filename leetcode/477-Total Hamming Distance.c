/*
 * Total Hamming Distance
 *
 * The Hamming distance between two integers is the number of positions at which
 * the corresponding bits are different.
 *
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 *
 * Example:
 *   Input: 4, 14, 2
 *   Output: 6
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010
 * (just showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(32, 0);
        int i, cnt = 0;
        for (int num : nums) {
            i = 0;
            while (num > 0) {
                bits[i++] += (num & 0x1);
                num = num >> 1;
            }
        }
        for (i = 0; i < 32; i++) {
            cnt += bits[i] * (n - bits[i]);
        }
        return cnt;
    }
};
