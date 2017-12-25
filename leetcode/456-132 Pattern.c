/*
 * 132 Pattern
 *
 * Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence
 * ai, aj, ak such that i < j < k and ai < ak < aj.
 * Design an algorithm that takes a list of n numbers as input and checks whether
 * there is a 132 pattern in the list.
 */

// Timing Complexity O(n^2), Space Complexity O(1)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int i, j, minval = INT_MAX;
        for (i = 0; i < n; i++) {
            minval = min(minval, nums[i]);
            for (j = i+1; j < n; j++) {
                if (nums[j] > minval && nums[j] < nums[i]) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Timing Complexity O(n), Space Complexity O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), i;
        if (n < 3) return false;
        vector<int> min_arr(n, 0);
        stack<int> s;
        min_arr[0] = nums[0];
        for (i = 1; i < n; i++) {
            min_arr[i] = min(min_arr[i-1], nums[i]);
        }
        for (i = n-1; i >= 0; i--) {
            if (nums[i] > min_arr[i]) {
                while (!s.empty() && s.top() <= min_arr[i])
                    s.pop();
                if (!s.empty() && s.top() < nums[i])
                    return true;
                s.push(nums[i]);
            }
        }
        return false;
    }
};
