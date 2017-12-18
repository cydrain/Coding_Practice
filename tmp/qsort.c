#include <stdio.h>

void qsort(int A[], int start, int end) {
    if (start >= end) return;
    int l = start, r = end;
    int x = A[start];
    while (l < r) {
        // check from right to left
        while (l < r && x <= A[r]) r--;
        if (l < r) A[l++] = A[r];
        // check from left to right
        while (l < r && x >= A[l]) l++;
        if (l < r) A[r--] = A[l];
    }
    A[r] = x;
    qsort(A, start, r-1);
    qsort(A, r+1, end);
}

int main(void) {
    int A[] = {3,6,2,9,0,1,7,5,4,8};
    int i;
    qsort(A, 0, 9);
    for (i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
