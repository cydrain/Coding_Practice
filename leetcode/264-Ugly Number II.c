/*
 * Ugly Number II
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed 1690. 
 */
int nthUglyNumber(int n) {
    vector<int> ugly(n, 1);
    int idx2, idx3, idx5;
    int i;
    
    idx2 = idx3 = idx5 = 0;
    for (i = 1; i < n; i++) {
        ugly[i] = min(ugly[idx2]*2, min(ugly[idx3]*3, ugly[idx5]*5));
        while (ugly[idx2]*2 <= ugly[i]) idx2++;
        while (ugly[idx3]*3 <= ugly[i]) idx3++;
        while (ugly[idx5]*5 <= ugly[i]) idx5++;
    }
    
    return ugly[n-1];
}
