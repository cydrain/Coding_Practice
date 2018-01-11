/*
 * Find All Duplicates in an Array
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 *   Input:  [4,3,2,7,8,2,3,1]
 *   Output: [2,3]
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<int> ans;
        while (i < n) {
            if (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } else {
                i++;
            }
        }
        for (i = 0; i < n; i++) {
            if (i != nums[i]-1) ans.push_back(nums[i]);
        }
        return ans;
    }
};
