/*
 * find the longest increasing substr
 */

#include <vector>
#include <iostream>
using namespace std;

void appendSubstr(vector<int> &v, int x) {
    int n = v.size();
    if (n == 0) {
        v.push_back(x);
        return;
    }

    int l = 0, r = n-1, m;
    while (l <= r) {
        m = l + (r-l)/2;
        if (v[m] == x) return;
        if (v[m] > x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    if (l < n) {
        v[l] = x;
    }
    else {
        v.push_back(x);
    }
}

void findLongestSubstr(vector<int> &s, vector<int> &v) {
    int i;
    for (i = 0; i < s.size(); i++) {
        appendSubstr(v, s[i]);
    }
}

int main(void) {
    int a[] = {3,6,1,4,0,8,5,7,9};
    vector<int> s(a,a+9);
    vector<int> v;
    findLongestSubstr(s, v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

