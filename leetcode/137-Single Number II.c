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


class Solution {
public:
    // num1中存储至少出现了1次的bit
    // num2中存储至少出现了2次的bit
    // num3中存储出现了3次的bit
    // 每轮更新，从num1和num2中清除出现了3次的bit
    int singleNumber(int A[], int n) {
        int num1 = 0, num2 = 0, num3 = 0;
        for (int i = 0; i < n; i++) {
            num3 = num2 & A[i];
            num2 = num1 & A[i] | num2;
            num1 = num1 | A[i];
            num1 = num1 & (~num3);
            num2 = num2 & (~num3);
        }
        return num1;
    }
};

