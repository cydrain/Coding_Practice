/*
 * Search for a Range
 *
 * Given a sorted array of integers, find the starting and ending
 * position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4]. 
 *
 */

    int searchLeft(int A[], int start, int end, int target) {
        if (start > end) return -1;
        if (start == end) {
            return (A[start] == target) ? start : -1;
        }
        int l = start, r = end, m;
        while (r-l > 1) {
            m = (l + r) / 2;
            if (A[m] == target) {
                r = m;
            }
            else if (A[m] > target) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (A[l] == target) return l;
        else if (A[r] == target) return r;
        else return -1;
    }
    int searchRight(int A[], int start, int end, int target) {
        if (start > end) return -1;
        if (start == end) {
            return (A[start] == target) ? start : -1;
        }
        int l = start, r = end, m;
        while (r-l > 1) {
            m = (l + r) / 2;
            if (A[m] == target) {
                l = m;
            }
            else if (A[m] > target) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (A[r] == target) return r;
        else if (A[l] == target) return l;
        else return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> range(2);
        range[0] = searchLeft(A, 0, n-1, target);
        range[1] = searchRight(A, 0, n-1, target);
        return range;
    }




    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> range(2, -1);
        int lower = 0;
        int upper = n;
        int mid;

        // Search for lower bound
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (A[mid] < target)
                lower = mid + 1;
            else
                upper = mid;
        }

        // If the target is not found, return (-1, -1)
        if (A[lower] != target)
            return range;
        range[0] = lower;

        // Search for upper bound
        upper = n;
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (A[mid] > target)
                upper = mid;
            else
                lower = mid + 1;
        }
        range[1] = upper - 1;

        return range;
    }



    int searchLeft(int A[], int start, int end, int target) {
        if (start > end) return -1;
        int l = start, r = end, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (A[m] == target) {
                r = m;
            }
            else if (A[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return (A[l] == target) ? l : -1;
    }
    int searchRight(int A[], int start, int end, int target) {
        if (start > end) return -1;
        int l = start, r = end, m;
        while (l < r) {
            m = l + (r - l) / 2 + 1;    // when searching right, need plus 1 here
            if (A[m] == target) {
                l = m;
            }
            else if (A[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return (A[l] == target) ? l : -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> r(2);
        r[0] = searchLeft(A, 0, n-1, target);
        r[1] = searchRight(A, 0, n-1, target);
        return r;
    }



    int searchRangeLeft(int A[], int start, int end, int target) {
        int m;
        while (start < end) {
            m = start + (end-start)/2;
            if (A[m] == target) {
                end = m;
            }
            else if (target < A[m]) {
                end = m - 1;
            }
            else {
                start = m + 1;
            }
        }
        return (A[start] == target) ? start : -1;
    }
    int searchRangeRight(int A[], int start, int end, int target) {
        int m;
        while (start < end) {
            m = start + (end-start+1)/2;
            if (A[m] == target) {
                start = m;
            }
            else if (target < A[m]) {
                end = m - 1;
            }
            else {
                start = m + 1;
            }
        }
        return (A[start] == target) ? start : -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        result[0] = searchRangeLeft(A, 0, n-1, target);
        result[1] = searchRangeRight(A, 0, n-1, target);
        return result;
    }

