/*
 * Permutation Sequence
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *   "123"
 *   "132"
 *   "213"
 *   "231"
 *   "312"
 *   "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 *
 */

/* C solution */
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> factor(n+1, 1);
        int i, idx;
        string s, r;
        
        for (i = 1; i <= n; i++) {
            factor[i] = i * factor[i-1];
            s += i + '0';
        }
        k--;
        for (i = n-1; i >= 0; i--) {
            idx = k / factor[i];
            k = k % factor[i];
            r += s[idx];
            s.erase(idx, 1);
        }
        
        return r;
    }


/* Java solution */
public class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder s = new StringBuilder();
        StringBuilder r = new StringBuilder();
        int[] factor = new int[n+1];
        int i, index;
        
        factor[0] = 1;
        for (i = 1; i <= n; i++) {
            factor[i] = i * factor[i-1];
            s.append((char)(i+'0'));
        }
        k--;
        for (i = n-1; i >= 0; i--) {
            index = k / factor[i];
            k = k % factor[i];
            r.append(s.charAt(index));
            s.deleteCharAt(index);
        }
        return r.toString();
    }
}

