/* Print combinations of strings from List of List of String
 *
 * Example input: [[quick, slow], [brown, red], [fox, dog]]
 *
 * Output:
 * quick brown fox
 * quick brown dog
 * quick red fox
 * quick red dog
 * slow brown fox
 * slow brown dog
 * slow red fox
 * slow red dog
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printAllComb_1(vector<vector<string> > &s) {
    int n = s.size();
    vector<string> res(1, "");
    vector<string> tmp;
    int i, j, k;
    for (i = 0; i < s.size(); i++) {
        for (j = 0; j < s[i].size(); j++) {
            for (k = 0; k < res.size(); k++) {
                if (res[k].empty()) {
                    tmp.push_back(s[i][j]);
                }
                else {
                    tmp.push_back(res[k]+" "+s[i][j]);
                }
            }
        }
        res = tmp;
        tmp.clear();
    }
    for (i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

void printAllComb_2(vector<vector<string> > &s, vector<string> &cs, int k) {
    if (k < s.size()) {
        for (int i = 0; i < s[k].size(); i++) {
            cs.push_back(s[k][i]);
            printAllComb_2(s, cs, k+1);
            cs.pop_back();
        }
    }
    else {
        for (int i = 0; i < cs.size(); i++) {
            cout << cs[i] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    vector<vector<string> > s(3);
    vector<string> p;

    s[0].push_back("quick");
    s[0].push_back("slow");
    s[1].push_back("brown");
    s[1].push_back("red");
    s[2].push_back("fox");
    s[2].push_back("dog");

    cout << "Solution 1: " << endl;
    printAllComb_1(s);

    cout << "Solution 2: " << endl;
    printAllComb_2(s, p, 0);

    return 0;
}

