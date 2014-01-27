/*
 * Subsets
 *
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 *
 * For example,
 * If S = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> p;
        int n = S.size();
        sort(S.begin(), S.end());
        for (int i = 0; i < (1<<n); i++) {
            p.clear();
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    p.push_back(S[j]);
                }
            }
            r.push_back(p);
        }
        return r;
    }


    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r(1);
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); i++) {
            int j = r.size();
            while (j--) {
                r.push_back(r[j]);
                r.back().push_back(S[i]);
            }
        }
        return r;
    }



    void subsets(vector<int> &S, int start, vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);
        for (int i = start; i < S.size(); i++) {
            path.push_back(S[i]);
            subsets(S, i+1, path, result);
            path.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > r;
        vector<int> path;
        subsets(S, 0, path, r);
        return r;
    }
