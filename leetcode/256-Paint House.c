/*
 * Paint House
 *
 * There are a row of n houses, each house can be painted with one of the three
 * colors: red, blue or green. The cost of painting each house with a certain
 * color is different. You have to paint all the houses such that no two adjacent
 * houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by a n x 3
 * cost matrix. For example, costs[0][0] is the cost of painting house 0 with color
 * red; costs[1][2] is the cost of painting house 1 with color green, and so on...
 * Find the minimum cost to paint all houses. 
 */
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int m = costs.size(), i;
        if (m == 0) return 0;
        int a, b, c;
        int tmpa, tmpb, tmpc;
        a = costs[0][0], b = costs[0][1], c = costs[0][2];
        for (i = 1; i < m; i++) {
            tmpa = min(b, c) + costs[i][0];
            tmpb = min(a, c) + costs[i][1];
            tmpc = min(a, b) + costs[i][2];
            a = tmpa;
            b = tmpb;
            c = tmpc;
        }
        return min(a, min(b, c));
    }
};
