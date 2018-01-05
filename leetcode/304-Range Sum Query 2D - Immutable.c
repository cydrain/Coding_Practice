/*
 * Range Sum Query 2D - Immutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
 */
class NumMatrix {
private:
    vector<vector<int>> accu;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        int i, j;
        accu = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                accu[i][j] = accu[i-1][j] + accu[i][j-1] - accu[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (accu[row2+1][col2+1] - accu[row2+1][col1] - accu[row1][col2+1] + accu[row1][col1]);
    }
};
