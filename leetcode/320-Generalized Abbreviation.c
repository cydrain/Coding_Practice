/*
 * Generalized Abbreviation
 *
 * Write a function to generate the generalized abbreviations of a word.
 *
 * Example:
 *
 * Given word = "word", return the following list (order does not matter):
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1",
 * "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */
class Solution {
public:
    void dfs(string& word, int i, int k, string p, vector<string>& r) {
        int len = word.length();
        if (i == len) {
            if (k != 0) p = p + to_string(k);
            r.push_back(p);
        } else {
            dfs(word, i+1, k+1, p, r);
            if (k != 0) p = p + to_string(k);
            p = p + string(1, word[i]);
            dfs(word, i+1, 0, p, r);
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(word, 0, 0, "", res);
        return res;
    }
};
