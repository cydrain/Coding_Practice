/*
 * Pascal's Triangle II
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1]. 
 *
 */

/* C solution */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p(1, 1);
        int i, j;
        for (i = 0; i < rowIndex; i++) {
            for (j = p.size()-1; j >= 1; j--) {
                p[j] += p[j-1];
            }
            p.push_back(1);
        }
        return p;
    }
};


/* Java solution */
public class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> r = new ArrayList<>();
        int i, j;
        for (i = 0; i <= rowIndex; i++) {
            for (j = r.size()-1; j >= 1; j--) {
                r.set(j, r.get(j)+r.get(j-1));
            }
            r.add(1);
        }
        return r;
    }
}

