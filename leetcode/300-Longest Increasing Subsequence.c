/*
 * Longest Increasing Subsequence
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
 * Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 *
 * Your algorithm should run in O(n2) complexity. 
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> r;
        int i;
        for (i = 0; i < nums.size(); i++) {
            auto it = lower_bound(r.begin(), r.end(), nums[i]);
            if (it == r.end()) r.push_back(nums[i]);
            else *it = nums[i];
        }
        return r.size();
    }
};
