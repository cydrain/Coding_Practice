/* 
 * Rotate Array
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve
 * this problem. 
 */

/* C solution */
class Solution {
public:
    // reverse the element from index "start" (included) to "end" (not included)
    void rotateHelper(int nums[], int start, int end) {
        if (start >= end) return;
        int i, j;
        for (i = start, j = end-1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k == 0) return;
        rotateHelper(nums, 0, n-k);
        rotateHelper(nums, n-k, n);
        rotateHelper(nums, 0, n);
    }
};

