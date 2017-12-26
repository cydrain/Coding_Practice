/*
 * Strobogrammatic Number II
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * For example,
 * Given n = 2, return ["11","69","88","96"]. 
 */
class Solution {
public:
    void findStrobogrammatic(int n, map<char,char>& m, string p, vector<string>& r) {
        int len = p.length();
        int mid = n / 2, odd = n % 2;
        if (len < mid) {
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (len == 0 && it->first == '0') continue;
                findStrobogrammatic(n, m, p+it->first, r);
            }
        } else if (len == mid && odd) {
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->first != it->second) continue;
                findStrobogrammatic(n, m, p+it->first, r);
            }
        } else if (len < n) {
            findStrobogrammatic(n, m, p+m[p[n-len-1]], r);
        } else {
            r.push_back(p);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        map<char,char> m = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        vector<string> r;
        findStrobogrammatic(n, m, "", r);
        return r;
    }
};
