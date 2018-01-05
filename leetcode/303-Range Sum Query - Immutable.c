/*
 * Range Sum Query - Immutable
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * Example:
 *
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *   sumRange(0, 2) -> 1
 *   sumRange(2, 5) -> -1
 *   sumRange(0, 5) -> -3
 */
class NumArray {
private:
    vector<int> accu;
public:
    NumArray(vector<int> nums) {
        accu.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            accu.push_back(accu.back() + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return (accu[j+1] - accu[i]);
    }
};
