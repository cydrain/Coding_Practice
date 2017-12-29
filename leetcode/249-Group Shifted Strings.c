/*
 * Group Shifted Strings
 *
 * Given a string, we can "shift" each of its letter to its successive letter,
 * for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 *
 *   "abc" -> "bcd" -> ... -> "xyz"
 *
 * Given a list of strings which contains only lowercase alphabets, group all
 * strings that belong to the same shifting sequence.
 *
 * For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 * A solution is:
 *  [
 *   ["abc","bcd","xyz"],
 *   ["az","ba"],
 *   ["acef"],
 *   ["a","z"]
 *  ]
 */
class Solution {
public:
    string getKey(string& s) {
        int len = s.length(), i;
        string r;
        for (i = 1; i < len; i++) {
            char c = (s[i] - s[i-1] + 26) % 26 + 'a';
            r = r + string(1,c);
        }
        return r;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        int n = strings.size(), i;
        for (i = 0; i < n; i++) {
            string key = getKey(strings[i]);
            m[key].push_back(strings[i]);
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
