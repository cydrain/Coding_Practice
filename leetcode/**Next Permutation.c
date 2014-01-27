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
