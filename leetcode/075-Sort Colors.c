/*
 * Sort Colors
 *
 * Given an array with n objects colored red, white or blue, sort them
 * so that objects of the same color are adjacent, with the colors in
 * the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 */

/* C solution */
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0, b = n-1;
        int i = 0;
        
        while (i <= b) {
            if (A[i] == 0) {
                swap(A[r++], A[i++]);
            }
            else if (A[i] == 2) {
                swap(A[b--], A[i]);
            }
            else {
                i++;
            }
        }
    }


/* Java solution */
public class Solution {
    public void swap(int[] A, int i, int j) {
        if (i == j) return;
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
    public void sortColors(int[] A) {
        int n = A.length;
        int r = 0, b = n-1, i = 0;
        while (i <= b) {
            if (A[i] == 0) {
                swap(A, r, i);
                r++;
                i++;
            } else if (A[i] == 1) {
                i++;
            } else {
                swap(A, b, i);
                b--;
            }
        }
    }
}

