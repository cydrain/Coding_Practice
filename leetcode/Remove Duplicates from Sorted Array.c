/*
 * Remove Duplicates from Sorted Array
 *
 * Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this
 * in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2]. 
 *
 */

    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return n;
        // p is the index of the last elem without duplicate
        int p = 0;
        for (int i = 1; i < n; i++) {
            // if not duplicate, copy it
            if (A[i] != A[p]) {
                A[++p] = A[i];
            }
        }
        return p+1;
    }
