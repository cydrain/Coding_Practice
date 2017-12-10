/*
 * Restore IP Addresses
 *
 * Given a string containing only digits, restore it by returning all
 * possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 */

/* C solution */
    void restoreIpAddresses(string s, int start, int level,
                            string ip, vector<string> &result) {
        int n = s.size();
        int val = 0;
        if ((n-start) > (4-level)*3) return;
        if ((n-start) < (4-level)) return;
        
        if (start == n && level == 4) {
            ip.resize(ip.size()-1);
            result.push_back(ip);
            return;
        }
        for (int i = start; i < start+3; i++) {
            val = val*10 + (s[i]-'0');
            if (val <= 255) {
                ip += s[i];
                restoreIpAddresses(s, i+1, level+1, ip+".", result);
            }
            if (val == 0) break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        restoreIpAddresses(s, 0, 0, "", r);
        return r;
    }


/* Java solution */
public class Solution {
    public void restoreIpAddrHelper(String s, int n, int start, String p, List<String> r) {
        int len = s.length();
        int num = 0, i;
        if (n == 4 && start == len) {
            r.add(p.substring(0, p.length()-1));
            return;
        }
        if ((len-start) > (4-n)*3) return;
        if ((len-start) < (4-n)) return;
        
        for (i = 0; i < 3 && start+i < len; i++) {
            num = num*10 + (s.charAt(start+i)-'0');
            if (i > 0 && num < 10) break;
            if (num > 255) break;
            restoreIpAddrHelper(s, n+1, start+i+1, p+num+".", r);
        }
    }
    public List<String> restoreIpAddresses(String s) {
        List<String> r = new ArrayList<>();
        if (s.equals("")) return r;
        restoreIpAddrHelper(s, 0, 0, "", r);
        return r;
    }
}

