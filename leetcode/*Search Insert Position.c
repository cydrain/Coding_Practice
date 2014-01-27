/*
 * Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the
 * target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 *  [1,3,5,6], 5 → 2
 *  [1,3,5,6], 2 → 1
 *  [1,3,5,6], 7 → 4
 *  [1,3,5,6], 0 → 0 
 *
 */

    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n-1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (A[m] == target) return m;
            if (A[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
