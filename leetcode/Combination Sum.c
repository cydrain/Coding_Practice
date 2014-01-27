/*
 * Combination Sum
 *
 * Given a set of candidate numbers (C) and a target number (T), find all
 * unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 *  All numbers (including target) will be positive integers.
 *  Elements in a combination (a1, a2, … , ak) must be in non-descending 
 *  order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *  The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 2,3,6,7 and target 7,
 *  A solution set is:
 *   [7]
 *   [2, 2, 3] 
 *
 */

    vector<vector<int> > combinationSum(vector<int> &C, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        
        for (int i = 0; i < C.size(); i++) {
            if (C[i] < target) {
                vector<vector<int> > t = combinationSum(C, target-C[i]);
                for (int j = 0; j < t.size(); j++) {
                    if (!t[j].empty() && C[i] >= t[j].back()) {
                        t[j].push_back(C[i]);
                        r.push_back(t[j]);
                    }
                }
            }
            else if (C[i] == target) {
                vector<int> s;
                s.push_back(target);
                r.push_back(s);
            }
        }
        return r;
    }



// solution II
    void combinationSum(vector<int> &C, int T, int idx, vector<int> &path, vector<vector<int> > &result) {
        if (T == 0) {
            result.push_back(path);
            return;
        }
        for (int i = idx; i < C.size(); i++) {
            if (C[i] <= T) {
                path.push_back(C[i]);
                combinationSum(C, T-C[i], i, path, result);
                path.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &C, int T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> path;
        vector<vector<int> > r;
        sort(C.begin(), C.end());
        combinationSum(C, T, 0, path, r);
        return r;
    }
