#include <stdio.h>
#include <math.h>

long solve(long n) {
    // Complete this function
    int cnt = 0;
    while (n) {
        if (n & 0x1 == 0) {
            cnt++;
        }
        n = n >> 1;
    }
    return pow(2,cnt);
}

int main() {
    printf("%d\n", solve(5));
    return 0;
}
