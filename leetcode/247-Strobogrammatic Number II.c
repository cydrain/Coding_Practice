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


class Solution {
public:
    vector<string> findStrobogrammatic(int n, int m) {
        if (m == 0) return vector<string>({""});
        if (m == 1) return vector<string>({"0","1","8"});
        vector<string> v = findStrobogrammatic(n, m-2);
        vector<string> res;
        for (int i = 0; i < v.size(); i++) {
            if (n != m) res.push_back("0"+v[i]+"0");
            res.push_back("1"+v[i]+"1");
            res.push_back("6"+v[i]+"9");
            res.push_back("8"+v[i]+"8");
            res.push_back("9"+v[i]+"6");
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        ans = findStrobogrammatic(n,n);
        return ans;
    }
};
