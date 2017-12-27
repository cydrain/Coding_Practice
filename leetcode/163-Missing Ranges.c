/*
 * Missing Ranges
 *
 * Given a sorted integer array where the range of elements are in the inclusive
 * range [lower, upper], return its missing ranges.
 *
 * For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * return ["2", "4->49", "51->74", "76->99"]. 
 */
class Solution {
public:
    void addMissingRange(vector<string>& res, long long l, long long r) {
        char buf[32];
        if (l > r) return;
        else if (l == r) {
            sprintf(buf, "%ld", l);
        } else {
            sprintf(buf, "%ld->%ld", l, r);
        }
        res.push_back(string(buf));
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> res;
        int i;
        if (n == 0) {
            addMissingRange(res, lower, upper);
        } else {
            addMissingRange(res, lower, (long long)nums[0]-1);
            for (i = 0; i < n-1; i++) {
                addMissingRange(res, (long long)nums[i]+1, (long long)nums[i+1]-1);
            }
            addMissingRange(res, (long long)nums.back()+1, upper);
        }
        return res;
    }
};
