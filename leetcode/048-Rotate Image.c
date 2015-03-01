/*
 * Rotate Image
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *
 */

    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        int i, j;
        
        for (i = 0; i < n; i++) {
            for (j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }


    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int i, j, tmp;
        for (i = 0; i < n/2; i++) {
            for (j = i; j < n-1-i; j++) {
                tmp = matrix[i][j];
                // bottom = left
                matrix[i][j] = matrix[n-1-j][i];
                // left = top
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                // top = right
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                // right = bottom
                matrix[j][n-1-i] = tmp;
            }
        }
    }


/* Java Solution */
public class Solution {
    public void swap(int[][] A, int i1, int j1, int i2, int j2) {
        if (i1 == i2 && j1 == j2) return;
        int tmp = A[i1][j1];
        A[i1][j1] = A[i2][j2];
        A[i2][j2] = tmp;
    }
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n == 0) return;
        int i, j;
        
        for (j = 0; j < n; j++) {
            for (i = 0; i < n/2; i++) {
                swap(matrix, i, j, n-i-1, j);
            }
        }
        for (j = 0; j < n; j++) {
            for (i = 0; i < j; i++) {
                swap(matrix, i, j, j, i);
            }
        }
    }
}

