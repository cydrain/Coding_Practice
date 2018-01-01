/*
 * Sort Transformed Array
 *
 * Given a sorted array of integers nums and integer values a, b and c. Apply a
 * quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.
 *
 * The returned array must be in sorted order.
 *
 * Expected time complexity: O(n)
 */
class Solution {
public:
    int calc(int num, int a, int b, int c) {
        return (a*num*num + b*num + c);
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), i, j, idx;
        vector<int> res(n, 0);
        i = 0, j = n-1;
        if (a > 0) {
            idx = n-1;
            while (i <= j) {
                if (calc(nums[i], a, b, c) < calc(nums[j], a, b, c)) {
                    res[idx--] = calc(nums[j--], a, b, c);
                } else {
                    res[idx--] = calc(nums[i++], a, b, c);
                }
            }
        } else {
            idx = 0;
            while (i <= j) {
                if (calc(nums[i], a, b, c) < calc(nums[j], a, b, c)) {
                    res[idx++] = calc(nums[i++], a, b, c);
                } else {
                    res[idx++] = calc(nums[j--], a, b, c);
                }
            }
        }
        return res;
    }
};
