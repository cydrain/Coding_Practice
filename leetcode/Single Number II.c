/*
 * Single Number II
 *
 * Given an array of integers, every element appears three times except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory? 
 *
 */

int singleNumber(int A[], int n) {
        int bit_count[32] = {0};
        int result = 0;
        int i, j;
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < 32; j++) {
                if (A[i] & (1<<j)) {
                    bit_count[j]++;
                }
            }
        }
        for (j = 0; j < 32; j++) {
            if (bit_count[j] % 3) {
                result |= 1<<j;
            }
        }
        
        return result;
    }

