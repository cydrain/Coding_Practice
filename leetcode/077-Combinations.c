/*
 * Combinations
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 * 
 */

/* C solution */
    void combine(int n, int k, int start, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            combine(n, k, i+1, path, result);
            path.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> path;
        combine(n, k, 1, path, r);
        return r;
    }


/* Java solution */
public class Solution {
    public void combineHelper(int n, int k, int start, List<Integer> p, List<List<Integer>> r) {
        if (p.size() == k) {
            List<Integer> tmp = new ArrayList<>();
            for (Integer i: p) {
                tmp.add(i);
            }
            r.add(tmp);
        } else {
            for (int i = start; i <= n; i++) {
                p.add(i);
                combineHelper(n, k, i+1, p, r);
                p.remove(p.size()-1);
            }
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> r = new ArrayList<>();
        List<Integer> p = new ArrayList<>();
        combineHelper(n, k, 1, p, r);
        return r;
    }
}
