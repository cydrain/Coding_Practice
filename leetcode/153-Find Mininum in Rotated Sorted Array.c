/*
 * Find Minimum in Rotated Sorted Array
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

int findMin(vector<int> &num) {
    int n = num.size();
    int l = 0, r = n-1, m;
    while (l < r) {
        m = l + (r-l)/2;
        if (num[m] > num[r]) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return num[l];
}


int findMin(vector<int> &num) {
    int n = num.size();
    int l = 0, r = n-1, m;
    while (r-l > 1) {
        m = l + (r-l)/2;
        if (num[l] <= num[m]) {
            if (num[m] <= num[r]) {
                return num[l];
            }
            else {
                l = m;
            }
        }
        else {
            r = m;
        }
    }
    return min(num[l], num[r]);
}

