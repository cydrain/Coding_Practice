/*
 * Super Ugly Number
 *
 * Write a program to find the nth super ugly number.
 *
 * Super ugly numbers are positive numbers whose all prime factors are in the 
 * given prime list primes of size k.
 * For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of
 * the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 *
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer. 
 */

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int np = primes.size();
    vector<int> ugly(n, INT_MAX);
    vector<int> idx(np, 0);
    int i, j;
    
    ugly[0] = 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < np; j++) {
            ugly[i] = min(ugly[i], ugly[idx[j]]*primes[j]);
        }
        for (j = 0; j < np; j++) {
            while (ugly[idx[j]]*primes[j] <= ugly[i]) idx[j]++; 
        }
    }
    
    return ugly[n-1];
}
