/*
 * Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as
 * the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and
 * its corresponding outputs are in the right-hand column.
 *   1,2,3 → 1,3,2
 *   3,2,1 → 1,2,3
 *   1,1,5 → 1,5,1
 *
 */

/* C solution */
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        int n = num.size();
        if (n < 2) return;
        for (i = n-2; i >= 0; i--) {
            for (j = n-1; j > i; j--) {
                if (num[j] > num[i]) {
                    swap(num[i], num[j]);
                    reverse(num.begin()+i+1, num.end());
                    return;
                }
            }
        }
        reverse(num.begin(), num.end());
    }


/* Java solution */
public class Solution {
    public void swap(int[] num, int i, int j) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    public void reverse(int[] num, int start, int end) {
        int i, j;
        for (i = start, j = end-1; i < j; i++, j--) {
            swap(num, i, j);
        }
    }
    public void nextPermutation(int[] num) {
        int n = num.length;
        int i, j;
        for (i = n-2; i >= 0; i--) {
            for (j = n-1; j > i; j--) {
                if (num[i] < num[j]) {
                    swap(num, i, j);
                    reverse(num, i+1, n);
                    return;
                }
            }
        }
        reverse(num, 0, n);
    }
}

