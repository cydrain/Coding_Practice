/*
 * Median of Two Sorted Arrays
 *
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *
 */

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0, b = 0, result = 0, odd = 0;
        bool isOdd = false;
        if ((m + n) % 2 == 0) {
            isOdd = true;
        }
        for (int i = 0 ; i < (m+n)/2+1; i++) {
            if (b == n) {
                result = A[a++];
            }
            else if (a == m) {
                result = B[b++];
            }
            else {
                if ((A[a] > B[b])) {
                    result = B[b++];
                }
                else {
                    result = A[a++];
                }
            }
            if (isOdd && (i+1) == (m+n)/2) {
                odd = result;
            }
        }
        return isOdd ? ((double)result+(double)odd)/2 : (double)result;
    }
