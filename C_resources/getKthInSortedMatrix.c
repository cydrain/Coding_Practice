// 给出一个矩阵，各行各列均有序，求第K个最小值
#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Cell {
public:
    int val;
    int x;
    int y;
    Cell(int v, int i, int j):val(v),x(i),y(j){}
};

class comp {
public:
    bool operator()(Cell *a, Cell *b) {
        return (a->val < b->val);
    }
};

int getKthInSortedMatrix(int matrix[][6], int rows, int cols, int k) {
    if (k > rows*cols) return -1;
    multiset<Cell*,comp> s;
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));
    Cell *c;
    int i = 0, j = 0;
    int cnt = 0;
    s.insert(new Cell(matrix[i][j],i,j));
    visited[i][j] = true;
    for (cnt = 1; cnt < k; cnt++) {
        c = *(s.begin());
        s.erase(s.begin());
        //cout << "#" << cnt << ":" << c->val << endl;
        if (c->x+1 < rows && !visited[c->x+1][c->y]) {
            visited[c->x+1][c->y] = true;
            Cell *down = new Cell(matrix[c->x+1][c->y], c->x+1, c->y);
            s.insert(down);
            //cout << "++ " << down->val << endl;
        }
        if (c->y+1 < cols && !visited[c->x][c->y+1]) {
            visited[c->x][c->y+1] = true;
            Cell *right = new Cell(matrix[c->x][c->y+1], c->x, c->y+1);
            s.insert(right);
            //cout << "++ " << right->val << endl;
        }
    }
    return (*(s.begin()))->val;
}

int main(void) {
    int matrix[5][6] = {{ 1, 5, 9,17,20,33},
                        { 3, 6,11,19,34,48},
                        { 7, 9,21,25,49,56},
                        {11,16,22,30,55,78},
                        {23,34,44,50,61,99}};
    int A[] = {2,5,7,10};
    int i;
    for (i = 0; i < 4; i++) {
        cout << "No." << A[i] << " -> ";
        cout << getKthInSortedMatrix(matrix, 5, 6, A[i]) << endl;
    }
    return 0;
}
