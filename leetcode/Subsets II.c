/*
 * Subsets II
 *
 * Given a collection of integers that might contain duplicates, S,
 * return all possible subsets.
 *
 * Note:
 *  Elements in a subset must be in non-descending order.
 *  The solution set must not contain duplicate subsets.
 *
 * For example,
 * If S = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 * 
 */

    void subsets(vector<int> &S, int start, vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);
        
        for (int i = start; i < S.size(); i++) {
            if (i != start && S[i] == S[i-1]) continue;
            path.push_back(S[i]);
            subsets(S, i+1, path, result);
            path.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        
        vector<vector<int> > r;
        vector<int> path;
        
        subsets(S, 0, path, r);
        return r;
    }
