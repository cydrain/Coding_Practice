// 给出一个含有1到N的整型数组的签名，示出其所有可能的字典最小的排列，
// 其中N<=9。
// 签名是这样计算的：比较相邻元素的大小，如果后者比前者大，输出I；反之输出D。
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool computePerm(string &signature, vector<bool> &visited, string &p) {
    int n = signature.length()+1;
    int level = p.length();
    int i, j;
    if (p.length() == n) {
        cout << p << endl;
        return true;
    }

    i = p[p.length()-1] - '0';
    if (signature[level-1] == 'I') {
        for (j = i+1; j <= n; j++) {
            if (visited[j]) continue;
            visited[j] = true;
            p += j+'0';
            computePerm(signature, visited, p);
            p.erase(p.length()-1);
            visited[j] = false;
        }
    }
    else {
        for (j = 1; j < i; j++) {
            if (visited[j]) continue;
            visited[j] = true;
            p += j+'0';
            computePerm(signature, visited, p);
            p.erase(p.length()-1);
            visited[j] = false;
        }
    }
    return false;
}

void computePerm(string &signature) {
    int n = signature.length()+1;
    vector<bool> visited(n+1, false);
    string s;
    int i;
    for (i = 1; i <= n; i++) {
        s = i+'0';
        visited[i] = true;
        if (computePerm(signature, visited, s)) {
            break;
        }
        visited[i] = false;
    }
}

int main(void) {
    vector<string> vs;
    vs.push_back("DDIIDI");
    int i;
    for (i = 0; i < vs.size(); i++) {
        cout << vs[i] << " -> ";
        computePerm(vs[i]);
    }
    return 0;
}

