/*
 * Remove Duplicates from Sorted Array II
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3]. 
 *
 */

    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) return n;
        
        int p = 1;
        for (int i = 2; i < n; i++) {
            if (A[i] != A[p] || A[i] != A[p-1]) {
                A[++p] = A[i];
            }
        }
        
        return p+1;
    }
