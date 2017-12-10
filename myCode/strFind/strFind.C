#include <iostream>
#include <string>
using namespace std;

void strFind(string str) {
    int len = str.length();
    int l = 0, r = 0;
    string s;
    while (r < len) {
        r = str.find(' ', l);
        if (r == string::npos) r = str.length();
        s = str.substr(l, r-l);
        cout << l << '-' << r << ' ' << s << endl;
        l = r + 1;
    }
}

int main(void) {
    strFind("aa bbb cc ddd");
    return 0;
}
