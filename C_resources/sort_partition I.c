// 求一维数组中最小的 K 个数
#include <iostream>
using namespace std;

int partition(int A[], int start, int end) {
    if (start > end) return -1;
    if (start == end) return start;
    int x = A[start], l = start, r = end;
    while (l < r) {
        while (l < r && x <= A[r]) r--;
        if (l < r) A[l++] = A[r];
        while (l < r && x >= A[l]) l++;
        if (l < r) A[r--] = A[l];
    }
    A[l] = x;
    return l;
}

void getTopK(int A[], int n, int k) {
    int start = 0, end = n-1;
    int index = partition(A, start, end);
    int i;
    while (index != k-1) {
        if (index > k-1) {
            end = index - 1;
            index = partition(A, start, end);
        }
        else {
            start = index + 1;
            index = partition(A, start, end);
        }
    }
    for (i = 0; i <= index; i++) {
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

    getTopK(num, 10, 6);

    printf("\n");

    return 0;
}

