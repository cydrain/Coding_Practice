#include <stdio.h>

unsigned long long sum1s(unsigned long long n)
{
    unsigned long long count = 0;
    unsigned long long factor = 1;
    unsigned long long high, curr, low;

    while (n >= factor) {
        low  = n % factor;
        curr = n / factor % 10;
        high = n / (factor * 10);

        printf("high = %ld, curr = %ld, low = %ld\n",
               high, curr, low);

        switch (curr) {
        case 0:
            count += high * factor;
            break;
        case 1:
            count += high * factor + low + 1;
            break;
        default:
            count += (high + 1) * factor;
            break;
        }

        factor *= 10;
    }

    return count;
}

int main()
{
    unsigned long long n;

    while (1) {
        printf("Please input n: ");
        scanf("%ld", &n);
        getchar();

        if (n == 0) break;
        printf("The count of 1 is: %ld\n", sum1s(n));
    }
    return 0;
}

