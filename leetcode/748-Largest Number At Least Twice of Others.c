/*
 * Largest Number At Least Twice of Others
 *
 * In a given integer array nums, there is always exactly one largest element.
 *
 * Find whether the largest element in the array is at least twice as much as
 * every other number in the array.
 *
 * If it is, return the index of the largest element, otherwise return -1.
 *
 * Example 1:
 *   Input: nums = [3, 6, 1, 0]
 *   Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the array
 * x, 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 *
 * Example 2:
 *  Input: nums = [1, 2, 3, 4]
 *  Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int idx0, idx1, i;
        if (nums[0] >= nums[1]) {
            idx0 = 0, idx1 = 1;
        } else {
            idx0 = 1, idx1 = 0;
        }
        for (i = 2; i < n; i++) {
            if (nums[i] >= nums[idx0]) {
                idx1 = idx0;
                idx0 = i;
            } else if (nums[i] >= nums[idx1]) {
                idx1 = i;
            }
        }
        if (nums[idx0] >= 2*nums[idx1]) {
            return idx0;
        } else {
            return -1;
        }
    }
};
