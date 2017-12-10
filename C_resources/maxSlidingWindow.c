// 局部最大值
// 输入一个长数组A，以及窗口大小w，输出一个数组B，
// B[i]代表移动窗口A[i]...A[i+w-1]的最大值。
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Pair {
public:
    int val;
    int index;
    Pair(int v, int i):val(v),index(i){}
};

class comp {
public:
    bool operator()(Pair *n1, Pair *n2) {
        if (n1->val > n2->val) return true;
        else if (n1->val < n2->val) return false;
        else if (n1->index < n2->index) return true;
        else if (n1->index > n2->index) return false;
        return false;
    }
};

void printVector(vector<int> &v) {
    if (v.empty()) return;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';;
    }
    cout << endl;
}
void printVector(vector<int> &v, int start, int end) {
    if (v.empty()) return;
    for (int i = start; i <= end; i++) {
        cout << v[i] << ' ';;
    }
    cout << endl;
}

void maxSlidingWindow(vector<int> &num, int w) {
    multiset<Pair*,comp> ms;
    vector<int> res;
    int i;
    // initialize the first w elements
    for (i = 0; i < w; i++) {
        ms.insert(new Pair(num[i],i));
        cout << "++ " << num[i] << endl;
    }
    for (i = w; i < num.size(); i++) {
        cout << i << " ==========" << endl;
        Pair *p = *(ms.begin());
        cout << p->val << endl;
        res.push_back(p->val);
        while (p->index <= i-w) {
            ms.erase(ms.begin());
            cout << "-- " << p->val << endl;
            p = *(ms.begin());
        }
        ms.insert(new Pair(num[i],i));
    }
    res.push_back((*(ms.begin()))->val);
    printVector(res);
}

int main(void) {
    int A[] = {1,3,-1,-3,5,3,0,6,3,4,2};
    vector<int> v(A,A+11);
    maxSlidingWindow(v, 3);
    return 0;
}

