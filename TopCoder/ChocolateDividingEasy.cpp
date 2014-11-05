#line 14 "ChocolateDividingEasy.cpp"
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class ChocolateDividingEasy {
public:
	int getMin(vector<vector<int>> a) {
		int n = a.size();
		int i, j;
		int r = a[0][0];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				r = min(r, a[i][j]);
			}
		}
		return r;
	}
	int findBest(vector <string> chocolate) {
		int m = chocolate.size();
		int n = chocolate[0].length();
		vector<vector<int>> w(m, vector<int>(n, 0));
		int i, j;
		int i1, i2, j1, j2;
		vector<vector<int>> cut(3, vector<int>(3, 0));
		int r;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				w[i][j] = chocolate[i][j] - '0';
			}
		}
		for (i = 1; i < m; i++) {
			w[i][0] += w[i-1][0];
		}
		for (j = 1; j < n; j++) {
			w[0][j] += w[0][j-1];
		}
		for (i = 1; i < m; i++) {
			for (j = 1; j < n; j++) {
				w[i][j] += w[i-1][j] + w[i][j-1] - w[i-1][j-1];
			}
		}
		r = w[0][0];
		for (i1 = 0; i1 < m-1; i1++) {
			for (i2 = i1+1; i2 < m-1; i2++) {
				for (j1 = 0; j1 < n-1; j1++) {
					for (j2 = j1+1; j2 < n-1; j2++) {
						cut[0][0] = w[i1][j1];
						cut[0][1] = w[i1][j2] - w[i1][j1];
						cut[0][2] = w[i1][n-1] - w[i1][j2];
						cut[1][0] = w[i2][j1] - w[i1][j1];
						cut[1][1] = w[i2][j2] - w[i1][j2] - w[i2][j1] + w[i1][j1];
						cut[1][2] = w[i2][n-1] - w[i1][n-1] - w[i2][j2] + w[i1][j2];
						cut[2][0] = w[m-1][j1] - w[i2][j1];
						cut[2][1] = w[m-1][j2] - w[m-1][j1] - w[i2][j2] + w[i2][j1];
						cut[2][2] = w[m-1][n-1] - w[m-1][j2] - w[i2][n-1] + w[i2][j2];
						r = max(r, getMin(cut));
					}
				}
			}
		}
		return r;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
