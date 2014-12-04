/* Given a string (1-d array), find if there is any sub-sequence that repeats
 * itself. Here, sub-sequence can be a non-contiguous pattern, with the same
 * relative order. 
 * Eg: 
 * 1. abab <------yes, ab is repeated 
 * 2. abba <---- No, a and b follow different order 
 * 3. acbdaghfb <-------- yes there is a followed by b at two places 
 * 4. abcdacb <----- yes a followed by b twice 
 *
 * The above should be applicable to ANY TWO (or every two) characters in the
 * string and optimum over time. 
 * In the sense, it should be checked for every pair of characters in the string
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// let dp[i][j] means the longest common substring between s1[0:i] and s2[0:j]
// if s[i] == s[j] && i != j, dp[i][j] = max{dp[i-1][j-1]+1, dp[i-1][j], dp[i][j-1]}
// if s[i] != s[j], dp[i][j] = max{dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}
bool findComSubStr(string &s) {
    int n = s.length();
    string ss = "#" + s;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (ss[i] == ss[j] && i != j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
            else {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
        }
    }
    return (dp[n][n] > 1);
}

int main(void) {
    vector<string> vs;
    vs.push_back(string("abab"));
    vs.push_back(string("abba"));
    vs.push_back(string("acbdaghfb"));
    vs.push_back(string("abcdacb"));
    bool res;
    for (int i = 0; i < vs.size(); i++) {
        res = findComSubStr(vs[i]);
        cout << vs[i] << " -> " << res << endl;
    }
    return 0;
}
