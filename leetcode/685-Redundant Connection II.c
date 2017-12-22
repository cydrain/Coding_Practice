/* 
 * Redundant Connection II
 *
 * In this problem, a rooted tree is a directed graph such that, there is exactly one
 * node (the root) for which all other nodes are descendants of this node, plus every
 * node has exactly one parent, except for the root node which has no parents.
 *
 * The given input is a directed graph that started as a rooted tree with N nodes
 * (with distinct values 1, 2, ..., N), with one additional directed edge added.
 * The added edge has two different vertices chosen from 1 to N, and was not an
 * edge that already existed.
 *
 * The resulting graph is given as a 2D-array of edges. Each element of edges is
 * a pair [u, v] that represents a directed edge connecting nodes u and v, where
 * u is a parent of child v.
 *
 * Return an edge that can be removed so that the resulting graph is a rooted tree
 * of N nodes. If there are multiple answers, return the answer that occurs last in
 * the given 2D-array.
 *
 * Example 1:
 *
 *   Input: [[1,2], [1,3], [2,3]]
 *   Output: [2,3]
 *   Explanation: The given directed graph will be like this:
 *   
 *       1
 *      / \
 *     v   v
 *     2 -> 3
 */

/*
 * There are two cases for the tree structure to be invalid.
 * 1) A node having two parents;
 *   including corner case: e.g. [[4,2],[1,5],[5,2],[5,3],[2,4]]
 * 2) A circle exists
 *
 * If we can remove exactly 1 edge to achieve the tree structure, a single node
 * can have at most two parents. So my solution works in two steps.
 *
 * 1) Check whether there is a node having two parents. 
 *    If so, store them as candidates A and B, and set the second edge invalid. 
 * 2) Perform normal union find. 
 *      If the tree is now valid 
 *          simply return candidate B
 *      else if candidates not existing 
 *          we find a circle, return current edge; 
 *      else 
 *          remove candidate A instead of B.
 */ 

class Solution {
public:
    int root(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = root(parent, parent[x]);
        return parent[x];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> e, candA, candB;
        // check node with two parents
        for (auto &e : edges) {
            if (parent[e[1]] == 0) {
                parent[e[1]] = e[0];
            } else {
                candA = {parent[e[1]], e[1]};
                candB = e;
                e[1] = 0;
            }
        }
        
        int i, u, v, pu;
        for (i = 0; i <= n; i++) parent[i] = i;
        for (auto &e : edges) {
            u = e[0], v = e[1];
            pu = root(parent, u);
            // if loop exist
            if (pu == v) {
                if (candA.empty()) return e;
                return candA;
            } else {
                parent[v] = pu;
            }
        }
        return candB;
    }
};

