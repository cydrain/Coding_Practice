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



int evalRPN(vector<string> &tokens) {
    stack<int> s;
    int n = tokens.size();
    int a, b, r;
    int i;
    
    for (i = 0; i < n; i++) {
        if (tokens[i] == "+") {
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a + b;
            s.push(r);
        }
        else if (tokens[i] == "-") {
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a - b;
            s.push(r);
        }
        else if (tokens[i] == "*") {
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a * b;
            s.push(r);
        }
        else if (tokens[i] == "/") {
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a / b;
            s.push(r);
        }
        else {
            s.push(atoi(tokens[i].c_str()));
        }
    }
    
    return s.top();
}

