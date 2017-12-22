/* 
 * Redundant Connection
 *
 * In this problem, a tree is an undirected graph that is connected and has no cycles.
 *
 * The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N),
 * with one additional edge added. The added edge has two different vertices chosen from 1 to N, and
 * was not an edge that already existed.
 *
 * The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v,
 * that represents an undirected edge connecting nodes u and v.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are
 * multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v]
 * should be in the same format, with u < v. 
 *
 * Example1:
 *   Input: [[1,2], [1,3], [2,3]]
 *   Output: [2,3]
 *   Explanation: The given undirected graph will be like this:
 *       1
 *      / \
 *     2 - 3
 */

class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> r(2, 0);
        int i, a, b;
        for (i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (i = 0; i < n; i++) {
            a = find(parent, edges[i][0]);
            b = find(parent, edges[i][1]);
            if (a == b) {
                return edges[i];
            } else {
                parent[b] = a;
            }
        }
    }
};

