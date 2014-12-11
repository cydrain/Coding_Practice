// Given an array [a1, a2, ..., an, b1, b2, ..., bn], transform it to
// [a1, b1, a2, b2, ..., an, bn].
// Requirement: time complexity O(nlogn), space complexity O(logn)
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void reorderSortedArray(vector<int> &A, int start, int end) {
    if (start >= end) return;
    int n = (end-start+1)/2;
    int k = n/2;
    if (k < 1) return;
    reverse(A.begin()+start+k, A.begin()+start+n);
    reverse(A.begin()+start+n, A.begin()+start+n+k);
    reverse(A.begin()+start+k, A.begin()+start+n+k);
    //printVector(A);
    reorderSortedArray(A, start, start+2*k-1);
    reorderSortedArray(A, start+2*k, end);
}

int main(void) {
    int A[] = {0,2,4,6,8,1,3,5,7,9};
    vector<int> v(A,A+10);
    reorderSortedArray(v, 0, v.size()-1);
    printVector(v);
    return 0;
}
