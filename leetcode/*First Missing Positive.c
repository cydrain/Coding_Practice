/* 
 * First Missing Positive
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 */

Your algorithm should run in O(n) time and uses constant space. 

    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i < n) {
            if (A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i]) {
                swap(A[A[i]-1], A[i]);
            }
            else {
                i++;
            }
        }
        for (i = 0; i < n; i++) {
            if (A[i] != i+1) {
                break;
            }
        }
        return i+1;
    }
