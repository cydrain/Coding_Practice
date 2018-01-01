/*
 * Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:

Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
 */
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<pair<int,int>> res;
        if (k <= 0 || n1*n2 == 0) return res;
        auto comp = [&nums1,&nums2](pair<int,int>& p1, pair<int,int>& p2) {
                        return nums1[p1.first]+nums2[p1.second] > nums1[p2.first]+nums2[p2.second]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> q(comp);
        q.emplace(0,0);
        while (k-- > 0 && !q.empty()) {
            auto idx = q.top();
            q.pop();
            res.emplace_back(nums1[idx.first], nums2[idx.second]);
            if (idx.first < n1-1) {
                q.emplace(idx.first+1, idx.second);
            }
            if (idx.first == 0 && idx.second < n2-1) {
                q.emplace(idx.first, idx.second+1);
            }
        }
        return res;
    }
};
