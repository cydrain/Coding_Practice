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
