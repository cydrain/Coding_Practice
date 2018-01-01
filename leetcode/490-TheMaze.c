/*
 * The Maze

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
 */
class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& d, int x, int y, int x1, int y1) {
        int m = maze.size(), n = maze[0].size();
        int i, j, k;
        for (k = 0; k < 4; k++) {
            i = x + dir[k][0], j = y + dir[k][1];
            if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0) {
                while (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0) {
                    i += dir[k][0], j += dir[k][1];
                }
                i -= dir[k][0], j -= dir[k][1];
                if (i == x1 && j == y1) return true;
                if (d[i][j] == false) {
                    d[i][j] = true;
                    if (dfs(maze, d, i, j, x1, y1)) return true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> dist(m, vector<bool>(n,false));
        dist[start[0]][start[1]] = true;
        return dfs(maze, dist, start[0], start[1], dest[0], dest[1]);
    }
};
