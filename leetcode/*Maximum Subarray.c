/*
 * Maximum Subarray
 *
 * Find the contiguous subarray within an array (containing at least
 * one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
 *
 */

    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxsum = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            sum = max(A[i], sum+A[i]);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }



    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int t = A[0], m = A[0];
        for (int i = 1; i < n; i++) {
            t = max(A[i], t+A[i]);
            m = max(m, t);
        }
        return m;
    }
