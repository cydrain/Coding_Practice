/*
 * Maximum Size Subarray Sum Equals k
 *
 * Given an array nums and a target value k, find the maximum length of a subarray
 * that sums to k. If there isn't one, return 0 instead.
 *
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit signed
 * integer range.
 *
 * Example 1:
 * Given nums = [1, -1, 5, -2, 3], k = 3,
 * return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
 *
 * Example 2:
 * Given nums = [-2, -1, 2, 1], k = 1,
 * return 2. (because the subarray [-1, 2] sums to 1 and is the longest) 
 */
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int i, j, sum, maxlen = 0;
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int i, j, sum = 0, maxlen = 0;
        for (i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) {
                maxlen = i+1;
            } else if (m.find(sum-k) != m.end()) {
                maxlen = max(maxlen, i-m[sum-k]);
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        return maxlen;
    }
};
