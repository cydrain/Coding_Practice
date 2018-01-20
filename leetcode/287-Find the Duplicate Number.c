/*
 * Find the Duplicate Number
 *
 * Given an array nums containing n + 1 integers where each integer is between 1
 * and n (inclusive), prove that at least one duplicate number must exist. Assume
 * that there is only one duplicate number, find the duplicate one. 
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0;
        while (i < n) {
            if (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } else {
                if (i != nums[i]-1) return nums[i];
                i++;
            }
        }
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        fast = nums[0];
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
