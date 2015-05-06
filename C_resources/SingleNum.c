#include <stdio.h>

int singleNum(int A[], int n) {
    int num1 = 0, num2 = 0, num3 = 0;
    int i;
    for (i = 0; i < n; i++) {
        num3 = num2 & A[i];
        num2 = (num1 & A[i]) | num2;
        num1 = num1 | A[i];
        printf("No.%d: (%x) %x %x %x\n", i, A[i], num1, num2, num3);
        num1 = num1 & (~num3);
        num2 = num2 & (~num3);
        printf("No.%d: (%x) %x %x %x\n", i, A[i], num1, num2, num3);
    }
    return num1;
}

int main(void) {
    int A[] = {1,2,1,1};
    int r = 0;
    r = singleNum(A, 4);
    printf("%d\n", r);
    return 0;
}

