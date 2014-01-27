/*
 * Merge Sorted Array
 *
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements from B.
 * The number of elements initialized in A and B are m and n respectively.
 *
 */

    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (m && n) {
            if (A[m-1] > B[n-1]) {
                A[m+n-1] = A[m-1];
                m--;
            }
            else {
                A[m+n-1] = B[n-1];
                n--;
            }
        }
        while (n) {
            A[n-1] = B[n-1];
            n--;
        }
    }




    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (n) {
            if (m && A[m-1] > B[n-1]) {
                A[m+n-1] = A[m-1];
                m--;
            }
            else {
                A[m+n-1] = B[n-1];
                n--;
            }
        }
    }
