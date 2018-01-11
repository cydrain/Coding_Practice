/*
 * Different Ways to Add Parentheses
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 *
 * Example 1
 *   Input: "2-1-1".
 *     ((2-1)-1) = 0
 *     (2-(1-1)) = 2
 *   Output: [0, 2]
 *
 * Example 2
 *   Input: "2*3-4*5"
 *     (2*(3-(4*5))) = -34
 *     ((2*3)-(4*5)) = -14
 *     ((2*(3-4))*5) = -10
 *     (2*((3-4)*5)) = -10
 *     (((2*3)-4)*5) = 10
 *   Output: [-34, -14, -10, -10, 10]
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.length(), i;
        char c;
        vector<int> ans;
        for (i = 0; i < len; i++) {
            c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                for (int v1 : diffWaysToCompute(input.substr(0,i))) {
                    for (int v2 : diffWaysToCompute(input.substr(i+1))) {
                        if (c == '+') {
                            ans.push_back(v1+v2);
                        } else if (c == '-') {
                            ans.push_back(v1-v2);
                        } else {
                            ans.push_back(v1*v2);
                        }
                    }
                }       
            }
        }
        if (ans.empty()) ans.push_back(stoi(input));
        return ans;
    }
};
