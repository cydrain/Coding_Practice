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

/* C solution */
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


/* Java solution */
public class Solution {
    public void permuteUniqueHelper(int[] num, boolean[] visited, List<Integer> p, List<List<Integer>> r) {
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
                if (i > 0 && num[i] == num[i-1] && !visited[i-1]) continue;
                visited[i] = true;
                p.add(num[i]);
                permuteUniqueHelper(num, visited, p, r);
                p.remove(p.size()-1);
                visited[i] = false;
            }
        }
    }
    public List<List<Integer>> permuteUnique(int[] num) {
        List<Integer> p = new ArrayList<>();
        List<List<Integer>> r = new ArrayList<>();
        boolean[] visited = new boolean[num.length];
        
        Arrays.sort(num);
        permuteUniqueHelper(num, visited, p, r);
        return r;
    }
}

