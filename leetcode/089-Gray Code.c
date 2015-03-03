/*
 * Gray Code
 *
 * The gray code is a binary numeral system where two successive values
 * differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits
 * in the code, print the sequence of gray code. A gray code sequence
 * must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 *   00 - 0
 *   01 - 1
 *   11 - 3
 *   10 - 2
 *
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to
 * the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 *
 */

/* C solution */
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        for (int i = 0; i < (1<<n); i++) {
            r.push_back(i ^ (i>>1));
        }
        return r;
    }



vector<int> grayCode(int n) {
    vector<int> r(1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = r.size()-1; j >= 0; --j) {
            r.push_back(r[j] | (1<<i));
        }
    }
    return r;
}


/* Java solution */
public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> r = new ArrayList<>();
        r.add(0);
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = r.size()-1; j >= 0; j--) {
                r.add(r.get(j) | (1<<i));
            }
        }
        return r;
    }
}

