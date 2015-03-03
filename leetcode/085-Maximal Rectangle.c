/*
 * Maximal Rectangle
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest
 * rectangle containing all ones and return its area. 
 *
 */

/* C solution */
    int maxHistogram(vector<int> &h) {
        stack<int> s;
        int i = 0, t;
        int area = 0;
        while (i < h.size()) {
            if (s.empty() || h[i] >= h[s.top()]) {
                s.push(i++);
            }
            else {
                t = s.top();
                s.pop();
                area = max(area, h[t] * (s.empty() ? i : (i-s.top()-1)));
            }
        }
        return area;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        vector<vector<int> > dp(row+1, vector<int>(col+1, 0));
        int i, j;
        int area = 0;
        for (i = row-1; i >= 0; i--) {
            for (j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = dp[i+1][j] + 1;
                }
            }
        }
        for (i = 0; i < row; i++) {
            area = max(area, maxHistogram(dp[i]));
        }
        return area;
    }


/* Java solution */
public class Solution {
    public int maximalRectangleHelper(int[] h) {
        int n = h.length;
        int i = 0, t, area = 0;
        Stack<Integer> s = new Stack<>();
        while (i < n) {
            if (s.empty() || h[i] >= h[s.peek()]) {
                s.push(i++);
            } else {
                t = s.pop();
                area = Math.max(area, h[t] * (s.empty() ? i : (i-s.peek()-1)));
            }
        }
        return area;
    }
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        if (m == 0) return 0;
        int n = matrix[0].length;
        int[][] mx = new int[m][n+1];
        int i, j, area = 0;
        for (i = m-1; i >= 0; i--) {
            for (j = 0; j < n; j++) {
                if (i == m-1) {
                    mx[i][j] = (matrix[i][j] == '0') ? 0 : 1;
                } else {
                    mx[i][j] = (matrix[i][j] == '0') ? 0 : mx[i+1][j] + 1;
                }
            }
        }
        for (i = 0; i < m; i++) {
            area = Math.max(area, maximalRectangleHelper(mx[i]));
        }
        return area;
    }
}

