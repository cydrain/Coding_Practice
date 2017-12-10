/*
 * Single Number
 *
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory? 
 *
 */

/* C solution */
    int singleNumber(int A[], int n) {
        int result = 0;
        int i;
        for (i = 0; i < n; i++) {
            result ^= A[i];
        }
        return result;
    }


/* Java solution */
public class Solution {
    public int singleNumber(int[] A) {
        int r = 0;
        for (int i = 0; i < A.length; i++) {
            r ^= A[i];
        }
        return r;
    }
}

