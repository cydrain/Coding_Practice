/*
 * Walls and Gates
DescriptionHintsSubmissionsDiscussSolution

You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 */
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int x, int y, int dist) {
        int m = rooms.size();
        int n = rooms[0].size();
        rooms[x][y] = dist;
        if (x+1 < m  && rooms[x+1][y] > dist+1) dfs(rooms, x+1, y, dist+1);
        if (x-1 >= 0 && rooms[x-1][y] > dist+1) dfs(rooms, x-1, y, dist+1);
        if (y+1 < n  && rooms[x][y+1] > dist+1) dfs(rooms, x, y+1, dist+1);
        if (y-1 >= 0 && rooms[x][y-1] > dist+1) dfs(rooms, x, y-1, dist+1);
    }
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int,int>> q;
        int x, y;
        q.push(make_pair(i,j));
        while (!q.empty()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            if (x+1 < m && rooms[x+1][y] > rooms[x][y]+1) {
                rooms[x+1][y] = rooms[x][y] + 1;
                q.push(make_pair(x+1,y));
            }
            if (x-1 >= 0 && rooms[x-1][y] > rooms[x][y]+1) {
                rooms[x-1][y] = rooms[x][y] + 1;
                q.push(make_pair(x-1,y));
            } 
            if (y+1 < n && rooms[x][y+1] > rooms[x][y]+1) {
                rooms[x][y+1] = rooms[x][y] + 1;
                q.push(make_pair(x,y+1));
            } 
            if (y-1 >= 0 && rooms[x][y-1] > rooms[x][y]+1) {
                rooms[x][y-1] = rooms[x][y] + 1;
                q.push(make_pair(x,y-1));
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    //dfs(rooms, i, j, 0);
                    bfs(rooms, i, j);
                }
            }
        }
    }
};
