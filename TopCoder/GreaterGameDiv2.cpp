#line 14 "GreaterGameDiv2.cpp"
#include <string>
#include <vector>
using namespace std;

class GreaterGameDiv2 {
	public:
	int calc(vector <int> snuke, vector <int> sothe) {
		int n = snuke.size();
		int point = 0;
		int i;
		for (i = 0; i < n; i++) {
			if (snuke[i] > sothe[i]) point++;
		}
		return point;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
