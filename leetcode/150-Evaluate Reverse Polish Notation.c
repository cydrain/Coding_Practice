/*
 * Evaluate Reverse Polish Notation
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int x, y;
        auto token = tokens.back();  tokens.pop_back();
        if (is_operator(token))  {
            y = evalRPN(tokens);
            x = evalRPN(tokens);
            if (token[0] == '+')       x += y;
            else if (token[0] == '-')  x -= y;
            else if (token[0] == '*')  x *= y;
            else                       x /= y;
        } else  {
            size_t i;
            x = stoi(token, &i);
        }
        return x;
    }
private:
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};


int evalRPN(vector<string> &tokens) {
    stack<int> sk;
    int val, a, b, r;
    int n = tokens.size();
    string s;
    int i;
    for (i = 0; i < n; i++) {
        s = tokens[i];
        if (isdigit(s[s.length()-1])) {
            val = atoi(s.c_str());
            sk.push(val);
        }
        else {
            b = sk.top(), sk.pop();
            a = sk.top(), sk.pop();
            if (s[0] == '+') {
                r = a + b;
            }
            else if (s[0] == '-') {
                r = a - b;
            }
            else if (s[0] == '*') {
                r = a * b;
            }
            else {
                r = a / b;
            }
            sk.push(r);
        }
    }
    return sk.top();
}

