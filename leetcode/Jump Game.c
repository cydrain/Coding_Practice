/*
 * Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false. 
 *
 */

    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, dist = 0;
        while (i <= dist) {
            dist = max(dist, i+A[i]);
            if (dist >= n-1) return true;
            i++;
        }
        return false;
    }
