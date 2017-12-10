/*
 * Remove Element
 *
 * Given an array and a value, remove all instances of that value
 * in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you
 * leave beyond the new length. 
 *
 */

/* C solution */
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, p = 0;
        for (i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[p++] = A[i];
            }
        }
        return p;
    }

/* Java solution */
public class Solution {
    public int removeElement(int[] A, int elem) {
        int p = 0, i;
        for (i = 0; i < A.length; i++) {
            if (A[i] != elem) {
                A[p++] = A[i];
            }
        }
        return p;
    }
}

