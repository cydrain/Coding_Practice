/*
 * Search a 2D Matrix
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 *
 * For example,
 * 
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 *
 * Given target = 3, return true.
 *
 */

/* C solution */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n-1, mid;
        
        while (l <= r) {
            mid = (l + r) / 2;
            if (matrix[mid/n][mid%n] == target) return true;
            if (matrix[mid/n][mid%n] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }


/* Java solution */
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int l = 0, r = m*n-1, mid;
        int x, y;
        while (l <= r) {
            mid = l + (r-l)/2;
            x = mid / n;
            y = mid % n;
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
}

