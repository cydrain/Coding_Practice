/* 
 * Given an array of integer, find the number of un-ordered pairs
 * in that array, say
 * given {1, 3, 2}, the answer is 1, because {3, 2} is un-ordered,
 * and for array {3, 2, 1}, the answer is 3, because {3, 2}, {3, 1},
 * {2, 1}. 
 */
#include <iostream>
using namespace std;

int solution1(int A[], int n) {
    int i, j;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (A[i] > A[j]) cnt++;
        }
    }
    return cnt;
}

void merge_array(int A[], int start, int mid, int end, int tmp[], int &cnt) {
    int i = start, j = mid+1, k = 0;
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            tmp[k++] = A[i++];
        }
        else {
            cnt += mid-i+1;
            tmp[k++] = A[j++];
        }
    }
    while (i <= mid) tmp[k++] = A[i++];
    while (j <= end) tmp[k++] = A[j++];
    for (i = 0; i < k; i++) {
        A[start+i] = tmp[i];
    }
}

void merge_sort(int A[], int start, int end, int tmp[], int &cnt) {
    if (start >= end) return;
    int mid = start + (end-start)/2;
    merge_sort(A, start, mid, tmp, cnt);
    merge_sort(A, mid+1, end, tmp, cnt);
    merge_array(A, start, mid, end, tmp, cnt);
}

int solution2(int A[], int n) {
    int *tmp = new int[n];
    int cnt = 0;
    merge_sort(A, 0, n-1, tmp, cnt);
    delete[] tmp;
    return cnt;
}

int main(void) {
    int A[] = {11,4,7,9,1,6,3,0,2,8,5};
    int n = 11;
    int cnt1 = solution1(A, n);
    int cnt2 = solution2(A, n);
    cout << "Solution1: " << cnt1 << endl;
    cout << "Solution2: " << cnt2 << endl;
    return 0;
}


