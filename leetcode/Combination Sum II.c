/*
 * Combination Sum II
 *
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *  All numbers (including target) will be positive integers.
 *  Elements in a combination (a1, a2, … , ak) must be in non-descending
 *  order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *  The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 *  A solution set is:
 *   [1, 7]
 *   [1, 2, 5]
 *   [2, 6]
 *   [1, 1, 6] 
 *
 */

    void combinationSum(vector<int> &C, int T, int idx, vector<int> &path, vector<vector<int> > &result) {
        if (T == 0) {
            result.push_back(path);
            return;
        }
        for (int i = idx; i < C.size(); i++) {
            if (C[i] > T) continue;
            if (i > idx && C[i] == C[i-1]) continue;
            path.push_back(C[i]);
            combinationSum(C, T-C[i], i+1, path, result);
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &C, int T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> path;
        vector<vector<int> > r;
        sort(C.begin(), C.end());
        combinationSum(C, T, 0, path, r);
        return r;
    }
