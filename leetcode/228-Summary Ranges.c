/*
 * Summary Ranges
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * Example 1:
 *   Input: [0,1,2,4,5,7]
 *   Output: ["0->2","4->5","7"]
 *
 * Example 2:
 *   Input: [0,2,3,4,6,8,9]
 *   Output: ["0","2->4","6","8->9"]
 */ 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> r;
        int i, start, end;
        for (i = 0; i < n; ) {
            start = end = i;
            while (end+1 < n && nums[end]+1 == nums[end+1]) end++;
            if (start == end) {
                r.push_back(to_string(nums[start]));
            } else {
                r.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            i = end + 1;
        }
        return r;
    }
};
