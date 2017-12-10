#include <stdio.h>

#define NUM 10
int guess(int num) {
    if (num < NUM) return -1;
    else if (num == NUM) return 0;
    else return 1;
}

int guessNumber(int n) {
    int l = 1, r = n, m;
    while (l <= r) {
        m = l + (r-l)/2;
        switch(guess(m)) {
            case -1:
                l = m + 1;
                break;
            case 0:
                return m;
            case 1:
                r = m - 1;
                break;
        }
    }
    return -1;
}

int main(void) {
    printf("%d\n", guessNumber(10));
}
