#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calc(vector<string> &tokens) {
    int sum = 0, m = 1;
    bool divide = false;
    string op;
    int num;

    for (int i = 0; i < tokens.size(); i++) {
        if (i % 2 == 0) {
            num = atoi(tokens[i].c_str());
            if (divide) {
                m /= num;
            }
            else {
                m *= num;
            }
        }
        else {
            op = tokens[i];
            divide = false;
            if (op == "+") {
                sum += m;
                m = 1;
            }
            else if (op == "-") {
                sum += m;
                m = -1;
            }
            else if (op == "/") {
                divide = true;
            }
        }
        cout << m << "  " << divide << "  " << sum << endl;
    }
    sum += m;
    return sum;
}

int main(void) {
    vector<string> tokens;
    tokens.push_back(string("4"));
    tokens.push_back(string("+"));
    tokens.push_back(string("5"));
    tokens.push_back(string("-"));
    tokens.push_back(string("6"));

    cout << calc(tokens) << endl;
    return 1;
}

