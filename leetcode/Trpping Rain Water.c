/*
 * Trapping Rain Water
 *
 * Given n non-negative integers representing an elevation map
 * where the width of each bar is 1, compute how much water it
 * is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
 *
 */

    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        int i, h, mid = 0;
        int water = 0;
        for (i = 1; i < n; i++) {
            if (A[i] > A[mid]) {
                mid = i;
            }
        }
        
        h = A[0];
        for (i = 1; i < mid; i++) {
            if (h > A[i]) {
                water += h - A[i];
            }
            else {
                h = A[i];
            }
        }
        
        h = A[n-1];
        for (i = n-2; i > mid; i--) {
            if (h > A[i]) {
                water += h - A[i];
            }
            else {
                h = A[i];
            }
        }
        return water;
    }



// solution 2
    int trap(int A[], int n) {
        int l = 0, r = n-1;
        int water = 0, i;
        while (l < r) {
            if (A[l] <= A[r]) {
                for (i = l+1; i < r && A[i] <= A[l]; i++) {
                    water += A[l] - A[i];
                }
                l = i;
            }
            else {
                for (i = r-1; i > l && A[i] <= A[r]; i--) {
                    water += A[r] - A[i];
                }
                r = i;
            }
        }
        return water;
    }

