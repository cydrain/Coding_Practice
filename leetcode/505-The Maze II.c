/*
 * The Maze II

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
 */
class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& distance) {
        int m = maze.size();
        int n = maze[0].size();
        int i, j, k, count = 0;
        for (k = 0; k < 4; k++) {
            i = x + dir[k][0], j = y + dir[k][1];
            count = 0;
            while (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0) {
                count++;
                i = i + dir[k][0], j = j + dir[k][1];
            }
            if (distance[i-dir[k][0]][j-dir[k][1]] > distance[x][y] + count) {
                distance[i-dir[k][0]][j-dir[k][1]] = distance[x][y] + count;
                dfs(maze, i-dir[k][0], j-dir[k][1], distance);
            }
        }
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[start[0]][start[1]] = 0;
        dfs(maze, start[0], start[1], distance);
        return (distance[dest[0]][dest[1]] == INT_MAX ? -1 : distance[dest[0]][dest[1]]);
    }
};
