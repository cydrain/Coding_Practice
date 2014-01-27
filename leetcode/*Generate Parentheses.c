/*
 * Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all
 * combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()" 
 *
 */

    void generator(int n, int lb, int rb, string s, vector<string> &r) {
        if (lb == n) {
            s.append(lb-rb, ')');
            r.push_back(s);
            return;
        }
        generator(n, lb+1, rb, s+'(', r);
        if (lb > rb) {
            generator(n, lb, rb+1, s+')', r);
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        generator(n, 0, 0, "", r);
        return r;
    }
