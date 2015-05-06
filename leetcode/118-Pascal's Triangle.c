/*
 * Pascal's Triangle
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 *
 * Return
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 * 
 */

/* C solution */
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> s;

        for (int i = 1; i <= numRows; i++) {
            for (int j = i-2; j > 0; j--) {
                s[j] += s[j-1];
            }
            s.push_back(1);
            r.push_back(s);
        }
        
        return r;
    }



    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> r;
        vector<int> p;
        for (int i = 0; i < numRows; i++) {
            for (int j = p.size()-1; j > 0; j--) {
                p[j] += p[j-1];
            }
            p.push_back(1);
            r.push_back(p);
        }
        return r;
    }


/* Java solution */
public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> r = new ArrayList<>();
        List<Integer> p = new ArrayList();
        int i, j;
        for (i = 0; i < numRows; i++) {
            for (j = p.size()-1; j >= 1; j--) {
                p.set(j, p.get(j)+p.get(j-1));
            }
            p.add(1);
            
            List<Integer> tmp = new ArrayList<>();
            for (Integer k: p) {
                tmp.add(k);
            }
            r.add(tmp);
        }
        return r;
    }
}

