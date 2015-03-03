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

/* C solution */
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


/* Java solution */
public class Solution {
    public void subsetsWithDupHelper(int[] num, int start, List<Integer> p, List<List<Integer>> r) {
        List<Integer> list = new ArrayList<>();
        for (Integer i: p) {
            list.add(i);
        }
        r.add(list);
        for (int i = start; i < num.length; i++) {
            if (i > start && num[i] == num[i-1]) continue;
            p.add(num[i]);
            subsetsWithDupHelper(num, i+1, p, r);
            p.remove(p.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] num) {
        List<List<Integer>> r = new ArrayList<>();
        List<Integer> p = new ArrayList<>();
        Arrays.sort(num);
        subsetsWithDupHelper(num, 0, p, r);
        return r;
    }
}

