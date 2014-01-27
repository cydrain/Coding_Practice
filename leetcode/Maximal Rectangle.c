/*
 * Maximal Rectangle
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest
 * rectangle containing all ones and return its area. 
 *
 */

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
