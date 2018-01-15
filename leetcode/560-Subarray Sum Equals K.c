/*
 * Subarray Sum Equals K
 *
 * Given an array of integers and an integer k, you need to find the total number
 * of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *   Input:nums = [1,1,1], k = 2
 *   Output: 2
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i, j, count = 0, sum;
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int i, count = 0, sum = 0;
        m[0] = 1;
        for (i = 0; i < n; i++) {
            sum += nums[i];
            count += m[sum-k];
            m[sum]++;
        }
        return count;
    }
};
