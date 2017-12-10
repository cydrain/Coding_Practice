// 给定一维整型数组和一个整数K，找出和不小于K 的数目最少的子数组
#include <iostream>
using namespace std;

// put the num bigger than x to the left of the array,
// put the num smaller than x to the right of the array.
// currSum store the sum of all nums bigger than or equal to x.
int partition(int A[], int start, int end, int &currSum) {
    int x = A[start], l = start, r = end;
    int i;
    if (start > end) {
        currSum = INT_MIN;
        return -1;
    }
    if (start == end) {
        currSum = A[start];
        return start;
    }
    while (l < r) {
        while (l < r && x >= A[r]) r--;
        if (l < r) A[l++] = A[r];
        while (l < r && x <= A[l]) l++;
        if (l < r) A[r--] = A[l];
    }
    A[l] = x;
    currSum = 0;
    for (i = start; i <= l; i++) {
        currSum += A[i];
    }
    return l;
}

void getTopK(int A[], int n, int k) {
    int start = 0, end = n-1;
    int currSum, last;
    int index = partition(A, start, end, currSum);
    int i;
    while (index >= 0) {
        if (currSum >= k) {
            last = index;
            end = index - 1;
            index = partition(A, start, end, currSum);
        }
        else {
            start = index + 1;
            k = k - currSum;
            index = partition(A, start, end, currSum);
        }
    }
    for (i = 0; i <= last; i++) {
        printf("%3d", A[i]);
    }
}

int main() {
    int num[10] = {41, 34, 89, 22, 6, 91, 53, 29, 66, 30};
    int i, k;

    printf("\nBefore sort: ");
    for (i = 0; i < 10; i++) {
        printf("%3d", num[i]);
    }
    printf("\n");

    getTopK(num, 10, 300);

    printf("\n");

    return 0;
}

