/*
 * Permutations II
 *
 * Given a collection of numbers that might contain duplicates, 
 * return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1]. 
 *
 */

    void permute(vector<int> &num, vector<bool> &visited, vector<int> &perm,
                 vector<vector<int> > &result) {
        if (perm.size() == num.size()) {
            result.push_back(perm);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (visited[i] || (i > 0 && num[i]==num[i-1] && !visited[i-1])) {
                continue;
            } 
            visited[i] = true;
            perm.push_back(num[i]);
            permute(num, visited, perm, result);
            perm.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        vector<bool> visited(n, false);
        vector<int> perm;
        vector<vector<int> > r;
        sort(num.begin(), num.end());
        permute(num, visited, perm, r);
        return r;
    }
