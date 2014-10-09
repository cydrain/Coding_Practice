/*
 * Median of Two Sorted Arrays
 *
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *
 */

    // find the No.k element, (1 <= k <= m+n)
    // i + j == k - 1
    int findKthSmall(int A[], int m, int B[], int n, int k) {
        int Ai, Ai_1, Bj, Bj_1;
        int i, j;
        
        i = (int)((double)m / (m+n) * (k-1));
        j = k - 1 - i;
        
        Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
        Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
        Ai   = ((i == m) ? INT_MAX : A[i]);
        Bj   = ((j == n) ? INT_MAX : B[j]);
        
        if (Ai_1 <= Bj && Bj <= Ai) {
            return Bj;
        }
        if (Bj_1 <= Ai && Ai <= Bj) {
            return Ai;
        }
        if (Ai <= Bj) {
            return findKthSmall(A+i+1, m-i-1, B, n, k-i-1);
        }
        else {
            return findKthSmall(A, m, B+j+1, n-j-1, k-j-1);
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double result = 0, prev = 0;
        bool isEven = false;
        
        if ((m+n) % 2 == 0) {
            isEven = true;
        }
        
        if (isEven) {
            prev = findKthSmall(A, m, B, n, (m+n)/2);
            result = findKthSmall(A, m, B, n, (m+n)/2+1);
            return (prev+result)/2;
        }
        else {
            result = findKthSmall(A, m, B, n, (m+n)/2+1);
            return result;
        }
    }


// another O(n) solution
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0, b = 0;
        double result = 0, prev = 0;
        bool isEven = false;
        int i;
        if ((m+n) % 2 == 0) {
            isEven = true;
        }
        for (i = 0; i <= (m+n)/2; i++) {
            prev = result;
            
            if (a == m) {
                result = B[b++];
            }
            else if (b == n) {
                result = A[a++];
            }
            else if (A[a] < B[b]) {
                result = A[a++];
            }
            else {
                result = B[b++];
            }
        }
        return (isEven ? (prev+result)/2 : result);
    }

