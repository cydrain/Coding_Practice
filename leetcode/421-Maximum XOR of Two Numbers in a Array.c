/*
 * Maximum XOR of Two Numbers in an Array
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 *
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 *
 * Example:
 *   Input: [3, 10, 5, 25, 2, 8]
 *   Output: 28
 *   Explanation: The maximum result is 5 ^ 25 = 28.
 */ 
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, maxval = 0, tmp, i;
        for (i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            tmp = maxval | (1 << i);
            for (int prefix : s) {
                if (s.find(prefix ^ tmp) != s.end()) {
                    maxval = tmp;
                    break;
                }
            }
        }
        return maxval;
    }
};
