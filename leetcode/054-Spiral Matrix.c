/*
 * Spiral Matrix
 *
 * Given a matrix of m x n elements (m rows, n columns), return all
 * elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix: 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 *
 * You should return [1,2,3,6,9,8,7,4,5]. 
 *
 */

/* C solution */
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        if (matrix.empty()) return r;
        int left = 0, right = matrix[0].size()-1;
        int bottom = 0, top = matrix.size()-1;
        int i;
        
        while (true) {
            for (i = left; i <= right; i++) {
                r.push_back(matrix[bottom][i]);
            }
            if (++bottom > top) break;
            
            for (i = bottom; i <= top; i++) {
                r.push_back(matrix[i][right]);
            }
            if (--right < left) break;
            
            for (i = right; i >= left; i--) {
                r.push_back(matrix[top][i]);
            }
            if (--top < bottom) break;
            
            for (i = top; i >= bottom; i--) {
                r.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        
        return r;
    }


/* Java solution */
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> r = new ArrayList<>();
        int rows = matrix.length;
        if (rows == 0) return r;
        int cols = matrix[0].length;
        if (cols == 0) return r;
        int left = 0, right = cols-1;
        int bottom = 0, top = rows-1;
        int i;
        
        while (true) {
            for (i = left; i <= right; i++) {
                r.add(matrix[bottom][i]);
            }
            if (++bottom > top) break;
            
            for (i = bottom; i <= top; i++) {
                r.add(matrix[i][right]);
            }
            if (--right < left) break;
            
            for (i = right; i >= left; i--) {
                r.add(matrix[top][i]);
            }
            if (--top < bottom) break;
            
            for (i = top; i >= bottom; i--) {
                r.add(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return r;
    }
}

