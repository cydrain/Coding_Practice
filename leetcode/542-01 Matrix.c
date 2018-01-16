/*
 * 01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:

0 0 0
0 1 0
0 0 0

Output:

0 0 0
0 1 0
0 0 0

Example 2:
Input:

0 0 0
0 1 0
1 1 1

Output:

0 0 0
0 1 0
1 2 1
 */ 
// DFS 1318ms
class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& distance, int i, int j, int d) {
        int m = matrix.size(), n = matrix[0].size();
        int k, x, y;
        distance[i][j] = d;
        for (k = 0; k < 4; k++) {
            x = i+dir[k], y = j+dir[k+1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (distance[x][y] == 0) continue;
                if (matrix[x][y] == 0) {
                    dfs(matrix, distance, x, y, 0);
                } else if (d+1 < distance[x][y]) {
                    dfs(matrix, distance, x, y, d+1);
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        int i, j, k, x, y;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dfs(matrix, ans, i, j, 0);
                }
            }
        }
        return ans;
    }
};


// BFS 198ms
class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int dir[5] = {0,1,0,-1,0};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        int i, j, k, x, y;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty()) {
            i = q.front().first, j = q.front().second;
            q.pop();
            for (k = 0; k < 4; k++) {
                x = i+dir[k], y = j+dir[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (dist[x][y] > dist[i][j]+1) {
                        dist[x][y] = dist[i][j] + 1;
                        q.emplace(x, y);
                    }
                }
            }
        }
        return dist;
    }
};


// DP 200ms
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, m+n));
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
                }
            }
        }
        for (i = m-1; i >= 0; i--) {
            for (j = n-1; j >= 0; j--) {
                if (i < m-1) dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
                if (j < n-1) dist[i][j] = min(dist[i][j], dist[i][j+1]+1);
            }
        }
        return dist;
    }
};
