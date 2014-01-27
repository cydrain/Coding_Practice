/*
 * Spiral Matrix II
 *
 * Given an integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 * You should return the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 */

    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n-1;
        int bottom = 0, top = n-1;
        int num = 1;
        int i;
        vector<vector<int> > r(n, vector<int>(n, 0));
        
        while (true) {
            for (i = left; i <= right; i++) {
                r[bottom][i] = num++;
            }
            if (++bottom > top) break;
            
            for (i = bottom; i <= top; i++) {
                r[i][right] = num++;
            }
            if (--right < left) break;
            
            for (i = right; i >= left; i--) {
                r[top][i] = num++;
            }
            if (--top < bottom) break;
            
            for (i = top; i >= bottom; i--) {
                r[i][left] = num++;
            }
            if (++left > right) break;
        }
        
        return r;
    }
