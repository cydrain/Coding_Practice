/*
 * Diagonal Traverse
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 *
 * Example:
 *
 * Input:
 *  [
 *   [ 1, 2, 3 ],
 *   [ 4, 5, 6 ],
 *   [ 7, 8, 9 ]
 *  ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        vector<vector<int>> v;
        vector<int> tmp;
        int i, j, x, y;
        for (i = 0; i < n; i++) {
            tmp.clear();
            for (j = 0; j < max(m,n); j++) {
                x = j, y = i-j;
                if (x < 0 || x >= m || y < 0 || y >= n) break;
                tmp.push_back(matrix[x][y]);
            }
            v.push_back(tmp);
        }
        for (i = 1; i < m; i++) {
            tmp.clear();
            for (j = 0; j < max(m,n); j++) {
                x = i+j, y = n-1-j;
                if (x < 0 || x >= m || y < 0 || y >= n) break;
                tmp.push_back(matrix[x][y]);
            }
            v.push_back(tmp);
        }
        for (i = 0; i < v.size(); i++) {
            if (i % 2 == 0) {
                ans.insert(ans.end(), v[i].rbegin(), v[i].rend());
            } else {
                ans.insert(ans.end(), v[i].begin(), v[i].end());
            }
        }
        return ans;
    }
};
