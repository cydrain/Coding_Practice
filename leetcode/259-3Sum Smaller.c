/*
 * 3Sum Smaller
 *
 * Given an array of n integers nums and a target, find the number of index triplets
 * i, j, k with 0 <= i < j < k < n that satisfy the condition
 * nums[i] + nums[j] + nums[k] < target.
 *
 * For example, given nums = [-2, 0, 1, 3], and target = 2.
 *
 * Return 2. Because there are two triplets which sums are less than 2:
 *   [-2, 0, 1]
 *   [-2, 0, 3]
 */
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        int i, l, r, cnt = 0;
        sort(nums.begin(), nums.end());
        for (i = 0; i < n-2; i++) {
            l = i+1, r = n-1;
            while (l < r) {
                if (nums[i]+nums[l]+nums[r] < target) {
                    cnt += r-l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return cnt;
    }
};