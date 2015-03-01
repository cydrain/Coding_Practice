/*
 * Jump Game II
 *
 * Given an array of non-negative integers, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2.
 * (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
 *
 */

    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int steps = 0;
        int curr_max = 0, next_max = 0;
        for (int i = 0; i < n; i++) {
            if (i > curr_max) {
                curr_max = next_max;
                steps++;
            }
            next_max = max(next_max, i+A[i]);
        }
        
        if (curr_max >= n-1) {
            return steps;
        }
        else {
            return -1;
        }
    }


/* Java solution */
public class Solution {
    public int jump(int[] A) {
        int n = A.length;
        int curr = 0, next = 0;
        int i, step = 0;
        for (i = 0; i < n; i++) {
            if (i > curr) {
                curr = next;
                step++;
            }
            next = Math.max(next, i+A[i]);
        }
        return step;
    }
}

