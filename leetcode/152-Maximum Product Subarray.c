/*
 * Maximum Product Subarray
 * 
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6. 
 */

int maxProduct(int A[], int n) {
    int maxtmp, mintmp, maxval;
    int i, t1, t2;
    maxtmp = mintmp = maxval = A[0];
    for (i = 1; i < n; i++) {
        t1 = maxtmp * A[i];
        t2 = mintmp * A[i];
        maxtmp = max(A[i], max(t1, t2));
        mintmp = min(A[i], min(t1, t2));
        maxval = max(maxval, maxtmp);
    }
    return maxval;
}

