/*
 * Search in Rotated Sorted Array II
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 *
 */

    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1, m;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            if (A[m] == target) return true;
            
            // left part is sorted
            if (A[l] < A[m]) {
                if (A[l] <= target && target < A[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            // right part is sorted
            else if (A[l] > A[m]) {
                if (A[m] < target && target <= A[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                l++;
            }
        }
        
        return false;
    }
