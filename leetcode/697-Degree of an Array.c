/*
 * Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int n = nums.size(), i;
        int degree = 0, minlen;
        for (i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        for (auto item : m) {
            if (item.second.size() > degree) {
                degree = item.second.size();
                minlen = item.second.back() - item.second[0] + 1;
            } else if (item.second.size() == degree) {
                minlen = min(minlen, item.second.back() - item.second[0] + 1);
            }
        }
        return minlen;
    }
};