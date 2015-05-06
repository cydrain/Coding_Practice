/*
 * Palindrome Partitioning
 *
 * Given a string s, partition s such that every substring of the
 * partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *  [
 *    ["aa","b"],
 *    ["a","a","b"]
 *  ]
 * 
 */

/* C solution */
    void partitionHelper(string &s, int start, vector<vector<bool> > &palin,
                         vector<string> &p, vector<vector<string> > &r) {
        if (start == s.length()) {
            r.push_back(p);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (palin[start][i]) {
                p.push_back(s.substr(start, i-start+1));
                partitionHelper(s, i+1, palin, p, r);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > r;
        vector<string> p;
        int n = s.length();
        if (n == 0) return r;
        vector<vector<bool> > palin(n, vector<bool>(n, false));
        int i, j;
        for (j = 0; j < n; j++) {
            for (i = 0; i <= j; i++) {
                if (s[i] == s[j] && ((j-i) < 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                }
            }
        }
        partitionHelper(s, 0, palin, p, r);
        return r;
    }


/* Java solution */
public class Solution {
    public void partitionHelper(String s, boolean[][] isPalin, int start,
                                List<String> p, List<List<String>> r) {
        int n = s.length();
        if (start == n) {
            List<String> list = new ArrayList<>();
            for (String ts: p) {
                list.add(ts);
            }
            r.add(list);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalin[start][i]) {
                    p.add(s.substring(start, i+1));
                    partitionHelper(s, isPalin, i+1, p, r);
                    p.remove(p.size()-1);
                }
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> r = new ArrayList<>();
        int n = s.length();
        if (n == 0) return r;
        List<String> p = new ArrayList<>();
        boolean[][] isPalin = new boolean[n][n];
        int i, j;
        
        for (j = 0; j < n; j++) {
            for (i = 0; i <= j; i++) {
                if (s.charAt(i) == s.charAt(j) &&
                    (j-i < 2 || isPalin[i+1][j-1])) {
                    isPalin[i][j] = true;
                }
            }
        }
        partitionHelper(s, isPalin, 0, p, r);
        return r;
    }
}

