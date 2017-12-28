/*
 * Evaluate Division

Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction. 
 */
class Solution {
    unordered_map<string, unordered_map<string,double>> m;
public:
    bool calc(string a, string b, unordered_map<string, unordered_map<string, double>>& m, 
              unordered_set<string>& s, double& val) {
        //if (m.find(a) == m.end()) return false;
        if (m[a].find(b) != m[a].end()) {
            val = m[a][b];
            return true;
        } else {
            for (auto mid : m[a]) {
                double tmp;
                if (s.find(mid.first) != s.end()) continue;
                s.insert(mid.first);
                if (calc(mid.first, b, m, s, tmp)) {
                    val = tmp * mid.second;
                    return true;
                }
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = values.size(), i;
        vector<double> res;
        for (i = 0; i < n; i++) {
            m[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if (values[i] != 0) {
                m[equations[i].second].insert(make_pair(equations[i].first, 1/values[i]));
            }
        }
        for (auto q : queries) {
            double val;
            unordered_set<string> s;
            if (calc(q.first, q.second, m, s, val)) {
                res.push_back(val);
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
