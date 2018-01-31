/*
 * Graph Valid Tree
 *
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to check whether these edges make
 * up a valid tree.
 *
 * For example:
 *
 * Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 *
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 *
 * Note: you can assume that no duplicate edges will appear in edges. Since all
 * edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges. 
 */
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        int i;
        for (i = 0; i < n; i++) parent[i] = i;
        for (auto e : edges) {
            int f = e.first;
            int s = e.second;
            while (f != parent[f]) f = parent[f];
            while (s != parent[s]) s = parent[s];
            if (f == s) return false;
            parent[s] = f;
            //printf("edge(%d, %d), parent[%d] = %d\n", e.first, e.second, s, f);
        }
        return (edges.size() == n-1);
    }
};
