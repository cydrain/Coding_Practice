/*
 * Friend Circles

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

Example 2:

Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

 */ 
class Solution {
public:
    void bfs(vector<vector<int>>& M, vector<bool>& visited, int idx) {
        queue<int> q;
        int j, x, n = M.size();
        q.push(idx);
        while (!q.empty()) {
            x = q.front(), q.pop();
            visited[x] = true;
            for (j = 0; j < n; j++) {
                if (M[x][j] && !visited[j]) {
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        int i, j;
        vector<bool> visited(n, false);
        int count = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (M[i][j] && !visited[j]) {
                    bfs(M, visited, j);
                    count++;
                }
            }
        }
        return count;
    }
};
