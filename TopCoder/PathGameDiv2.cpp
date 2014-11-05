#line 14 "PathGameDiv2.cpp"
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class PathGameDiv2 {
public:
	int getBlackCnt(vector<string> &board) {
		int m = board.size();
		int n = board[0].size();
		int i, j, cnt = 0;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (board[i][j] == '#') {
					cnt++;
				}
			}
		}
		return cnt;
	}
	bool calcHelper(vector<string> &board, int x, int y) {
		if (board[x][y] == '#') return false;
		int n = board[0].size();
		
		// mark current cell as visited
		board[x][y] = '*';
		
		// if reach the right-most column, return true
		if (y == n-1) {
			board[1-x][y] = '#';
			return true;
		}
		
		if (board[x][y+1] == '.') {
			// move to right
			board[1-x][y] = '#';
			return calcHelper(board, x, y+1);
		}
		
		if (board[1-x][y] == '.') {
			// move to up or down
			return calcHelper(board, 1-x, y);
		}
		
		// should not happen
		return false;
	}
	int calc(vector <string> board) {
		vector<string> b1(board);
		vector<string> b2(board);
		int old, new1 = 0, new2 = 0;
		old = getBlackCnt(board);
		if (calcHelper(b1, 0, 0)) {
			new1 = getBlackCnt(b1);
		}
		if (calcHelper(b2, 1, 0)) {
			new2 = getBlackCnt(b2);
		}
		return max(new1, new2) - old;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
