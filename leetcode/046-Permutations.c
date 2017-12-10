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

/* C solution */
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


/* Java solution */
public class Solution {
    public void permuteHelper(int[] num, boolean[] visited, List<Integer> p, List<List<Integer>> r) {
        int n = num.length;
        if (p.size() == n) {
            List<Integer> tmp = new ArrayList<>();
            for (Integer i: p) {
                tmp.add(i);
            }
            r.add(tmp);
        } else {
            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;
                visited[i] = true;
                p.add(num[i]);
                permuteHelper(num, visited, p, r);
                p.remove(p.size()-1);
                visited[i] = false;
            }
        }
    }
    public List<List<Integer>> permute(int[] num) {
        List<Integer> p = new ArrayList<>();
        List<List<Integer>> r = new ArrayList<>();
        boolean[] visited = new boolean[num.length];
        
        permuteHelper(num, visited, p, r);
        return r;
    }
}

