/*
 * Number of Boomerangs
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals the
 * distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 *
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */
class Solution {
public:
    int getDist(pair<int,int>& p1, pair<int,int>& p2) {
        int dx = p1.first - p2.first;
        int dy = p1.second - p2.second;
        return (dx*dx + dy*dy);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size(), count = 0;
        int i, j, dist;
        unordered_map<int,int> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j == i) continue;
                dist = getDist(points[i], points[j]);
                if (m.find(dist) == m.end()) {
                    m[dist] = 1;
                } else {
                    m[dist]++;
                }
            }
            for (auto it = m.begin(); it != m.end(); it++) {
                count += it->second * (it->second-1);
            }
            m.clear();
        }
        return count;
    }
};
