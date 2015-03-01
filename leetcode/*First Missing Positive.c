/* 
 * First Missing Positive
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space. 
 */

/* C solution */
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


/* Java solution */
public class Solution {
    public void swap(int[] A, int i, int j) {
        if (i == j) return;
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
    public int firstMissingPositive(int[] A) {
        int n = A.length;
        int i = 0;
        while (i < n) {
            if (A[i] >= 1 && A[i] <= n && A[i] != A[A[i]-1]) {
                swap(A, i, A[i]-1);
            } else {
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
}

