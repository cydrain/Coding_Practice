#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

class Calculator {
private:
	vector<string> tokens;
public:
	~Calculator() { tokens.clear(); }
	void run();
private:
	bool checkDigit(string&);
	bool checkOperator(string&);
	float execute();
	bool parseLine(string&);
};

bool Calculator::checkDigit(string& str) {
	int len = str.length();
	int i, dot = 0;
	for (i = 0; i < len; i++) {
		if (str[i] == '.') {
			dot++;
		}
		else if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return (dot <= 1);
}

bool Calculator::checkOperator(string& str) {
	int len = str.length();
	if (len != 1) return false;
	return (str[0] == '+' ||
			str[0] == '-' ||
			str[0] == '*' ||
			str[0] == '/');
}

float Calculator::execute() {
    stack<float> s;
    int n = tokens.size();
    float a, b, r;
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
			float f = stringToNum<float>(tokens[i]);
			s.push(f);
        }
    }
    return s.top();
}

bool Calculator::parseLine(string& buf) {
	char *line, *p;
	string num, op;
	
	try {
		line = strdup(buf.c_str());
		p = strtok(line, " ");
		num = string(p);
		if (checkDigit(num)) {
			tokens.push_back(num);
		} else {
			throw exception();
		}

		p = strtok(NULL, " ");
		while (p != NULL) {
			num = string(p);
			if (checkDigit(num)) {
				tokens.push_back(num);
			} else {
				throw exception();
			}
			p = strtok(NULL, " ");

			if (p == NULL) throw exception();
			op = string(p);
			if (checkOperator(op)) {
				tokens.push_back(op);
			} else {
				throw exception();
			}
			p = strtok(NULL, " ");
		}
	}
	catch(...) {
		cout << "Invalud Expression!" << endl;
		free(line);
		return false;
	}
	free(line);
	return true;
}

void Calculator::run() {
	string buf;
	while (true) {
		cout << "Enter expression: ";
		getline(cin, buf);

		if (buf == "exit") break;

		if (parseLine(buf)) {
			cout << execute() << endl;
		}
	}
}

int main(int argc, const char* argv[]) {
	Calculator *calc = new Calculator();
	calc->run();
	return 0;
}
