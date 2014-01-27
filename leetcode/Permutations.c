/*
 * Permutations
 *
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
 *
 */

    void permute(vector<int> &num, vector<bool> &visited, vector<int> &perm, vector<vector<int> > &result) {
        if (perm.size() == num.size()) {
            result.push_back(perm);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                perm.push_back(num[i]);
                permute(num, visited, perm, result);
                perm.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        vector<bool> visited(n, false);
        vector<int> perm;
        vector<vector<int> > r;
        permute(num, visited, perm, r);
        return r;
    }
