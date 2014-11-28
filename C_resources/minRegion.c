/*
 * We have words and there positions in a paragraph in sorted order.
 * Write an algorithm to find the least distance for a given 3 words. 
 * eg. for 3 words 
 * job: 5, 9 , 17 
 * in: 4, 13, 18 
 * google: 8, 19, 21 
 * ... ... 
 * Answer: 17, 18, 19 
 * Can you extend it to "n" words? 
 */

#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

int minRegion(vector<int> &A, vector<int> &B, vector<int> &C) {
    int alen = A.size();
    int blen = B.size();
    int clen = C.size();
    int i = 0, j = 0, k = 0;
    int minDist = INT_MAX;
    int minval, maxval;

    cout << alen << ' ' << blen << ' ' << clen << endl;
    while (i < alen && j < blen && k < clen) {
        minval = min(A[i], min(B[j], C[k]));
        maxval = max(A[i], max(B[j], C[k]));
        minDist = min(minDist, maxval-minval);
        cout << A[i] << ' ' << B[j] << ' ' << C[k];
        cout << " minDist = " << minDist << endl;
        if (minval == A[i]) i++;
        else if (minval == B[j]) j++;
        else k++;
    }
    return minDist;
}

int main(void) {
    int A[] = {4, 10, 15, 24, 26};
    int B[] = {0, 9, 12, 20};
    int C[] = {5, 18, 22, 30};

    vector<int> va(A, A+sizeof(A)/sizeof(int));
    vector<int> vb(B, B+sizeof(B)/sizeof(int));
    vector<int> vc(C, C+sizeof(C)/sizeof(int));
    minRegion(va, vb, vc);
    return 0;
}
