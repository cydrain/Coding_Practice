/*
 * Factor Combinations

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.

Write a function that takes an integer n and return all possible combinations of its factors.

Note:

    You may assume that n is always positive.
    Factors should be greater than 1 and less than n.

Examples:
input: 1
output:

[]

input: 37
output:

[]

input: 12
output:

[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

input: 32
output:

[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 */ 
class Solution {
public:
    void getFactors(int n, vector<int>& p, vector<vector<int>>& r) {
        if (n == 1 && p.size() > 1) {
            r.push_back(p);
        } else {
            for (int i = (!p.empty() ? p.back() : 2); i <= n; i++) {
                if (n % i) continue;
                p.push_back(i);
                getFactors(n/i, p, r);
                p.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> p;
        getFactors(n, p, res);
        return res;
    }
};
