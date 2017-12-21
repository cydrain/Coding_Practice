//
//  main.cpp
//  myCalc
//
//  Created by caiyd on 17/12/21.
//  Copyright © 2017年 caiyd. All rights reserved.
//
//  Design a calculator which can implement '+', '-', '*', '/'

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

float Calculator::execute() {
    stack<float> s;
    int n = tokens.size();
    float a, b, r;
    int i;
    
    for (i = 0; i < n; i++) {
        if (tokens[i] == "+") {
            if (s.size() < 2) goto FAIL;
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a + b;
            s.push(r);
        }
        else if (tokens[i] == "-") {
            if (s.size() < 2) goto FAIL;
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a - b;
            s.push(r);
        }
        else if (tokens[i] == "*") {
            if (s.size() < 2) goto FAIL;
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a * b;
            s.push(r);
        }
        else if (tokens[i] == "/") {
            if (s.size() < 2) goto FAIL;
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            r = a / b;
            s.push(r);
        }
        else if (checkDigit(tokens[i])) {
            float f = stringToNum<float>(tokens[i]);
            s.push(f);
        } else {
            goto FAIL;
        }
    }
    tokens.clear();
    if (s.size() != 1) throw exception();
    return s.top();
FAIL:
    tokens.clear();
    throw exception();
}

bool Calculator::parseLine(string& buf) {
    char *line, *p;
    
    line = strdup(buf.c_str());
    p = strtok(line, " ");
    while (p != NULL) {
        tokens.push_back(p);
        p = strtok(NULL, " ");
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
        
        try {
            if (parseLine(buf) && tokens.size() > 0) {
                cout << execute() << endl;
            }
        }
        catch(...) {
            cout << "Invalid Expression!" << endl;
        }
    }
}

int main(int argc, const char* argv[]) {
    Calculator *calc = new Calculator();
    calc->run();
    return 0;
}
