/*
 * Relative Ranks
 *
 * Given scores of N athletes, find their relative ranks and the people with the
 * top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal"
 * and "Bronze Medal".
 *
 * Example 1:
 *   Input: [5, 4, 3, 2, 1]
 *   Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so they
 * got "Gold Medal", "Silver Medal" and "Bronze Medal". 
 * For the left two athletes, you just need to output their relative ranks according
 * to their scores.
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n);
        priority_queue<pair<int,int>> pq;
        int i, rank;
        for (i = 0; i < n; i++) {
            pq.push(make_pair(nums[i],i));
        }
        rank = 1;
        for (i = 0; i < n; i++) {
            if (rank == 1) {
                ans[pq.top().second] = "Gold Medal";
                rank++;
            } else if (rank == 2) {
                ans[pq.top().second] = "Silver Medal";
                rank++;
            } else if (rank == 3) {
                ans[pq.top().second] = "Bronze Medal";
                rank++;
            } else {
                ans[pq.top().second] = to_string(rank++);
            }
            pq.pop();
        }
        return ans;
    }
};
