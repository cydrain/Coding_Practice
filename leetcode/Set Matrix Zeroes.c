/*
 * Set Matrix Zero
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column
 * to 0. Do it in place.
 *
 * Follow up:
 * 
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * 
 */

    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool firstRowHas0 = false, firstColHas0 = false;
        int m = matrix.size(), n = matrix[0].size();
        int i, j;
        // check whether first col has 0
        for (i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColHas0 = true;
                break;
            }
        }
        // check whether first row has 0
        for (j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowHas0 = true;
                break;
            }
        }
        // check other elements, if it's 0, mark first elem in the row to 0,
        // and mark first elem in the col to 0.
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // iterate all elem in this matrix, except the first row and first col
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowHas0) {
            for (j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColHas0) {
            for (i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
