#include <iostream>
#include <vector>
using namespace std;
// 1. bubble sorting
void bubble_sort2(int A[], int n) {
    int i, j;
    bool flag;
    for (i = n-1; i > 0; i--) {
        flag = false;
        for (j = 0; j < i; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void bubble_sort3(int A[], int n) {
    int i, j, k;
    int flag = n-1;
    for (i = n-1; i > 0; i--) {
        k = flag;
        flag = 0;
        for (j = 0; j < k; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                flag = j;
            }
        }
    }
}

// 2. insert sorting
void insert_sort(int A[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; A[j] < A[j-1]; j--) {
            swap(A[j], A[j-1]);
        }
    }
}


// 3. select sorting
void select_sort(int A[], int n) {
    int i, j;
    int idx = 0;
    for (i = 0; i < n; i++) {
        idx = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[idx]) {
                idx = j;
            }
        }
        if (idx != i) {
            swap(A[idx], A[i]);
        }
    }
}

// 4. shell sorting
void shell_sort(int a[], int n) {  
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {  //步长
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && a[j] > a[j+gap]; j -= gap) {
                swap(a[j], a[j+gap]);
            }
        }
    }
}

// 5. quick sorting
void quick_sort(int A[], int start, int end) {
    if (start >= end) return;
    int l = start, r = end;
    int x = A[start];
    while (l < r) {
        // search from right to left, find the first num less than x
        while (l < r && A[r] >= x) {
            r--;
        }
        if (l < r) A[l++] = A[r];

        // search from left to right, find the first num bigger than x
        while (l < r && A[l] <= x) {
            l++;
        }
        if (l < r) A[r--] = A[l];
    }
    A[r] = x;
    quick_sort(A, start, r-1);
    quick_sort(A, r+1, end);
}
void quick_sort(int A[], int n) {
    quick_sort(A, 0, n-1);
}

// 6. merge sorting
void merge_array(int A[], int first, int mid, int last, int tmp[]) {
    int m = mid, n = last;
    int i = first, j = mid+1, k = 0;
    while (i <= m && j <= n) {
        if (A[i] <= A[j]) {
            tmp[k++] = A[i++];
        }
        else {
            tmp[k++] = A[j++];
        }
    }
    while (i <= m) tmp[k++] = A[i++];
    while (j <= n) tmp[k++] = A[j++];

    for (i = 0; i < k; i++) {
        A[first+i] = tmp[i];
    }
}
void merge_sort(int A[], int first, int last, int tmp[]) {
    if (first >= last) return;
    int mid = (first + last) / 2;
    merge_sort(A, first, mid, tmp);     // sort left part
    merge_sort(A, mid+1, last, tmp);    // sort right part
    merge_array(A, first, mid, last, tmp);  // merge left & right part
}
void merge_sort(int A[], int n) {
    int *p = new int[n];
    if (!p) return;
    merge_sort(A, 0, n-1, p);
    delete[] p;
    return;
}

// 7. heap sorting
// insert the ith node
void maxHeapFixUp(int A[], int i) {
    int x = A[i];
    int j = (i-1)/2;    // j is parent of i
    while (j >= 0 && i != 0) {
        if (A[j] >= x) break;
        // move small node downward
        A[i] = A[j];
        i = j;
        j = (i-1)/2;
    }
    A[i] = x;
}
// adjust max heap from ith node, total n nodes
void maxHeapFixDown(int A[], int i, int n) {
    int x = A[i];
    int j = 2*i+1;  // j is left child of i
    while (j < n) {
        if (j+1 < n && A[j+1] > A[j]) j++; // select the bigger child
        if (x >= A[j]) break;
        A[i] = A[j];
        i = j;
        j = 2*i+1;
    }
    A[i] = x;
}
void heap_sort(int A[], int n) {
    int i;
    // node from "(n-1)/2+1" to "n-1" are leaf nodes, need not fix down
    // after this loop, this array is a max heap array
    for (i = (n-1)/2; i >= 0; i--) {
        maxHeapFixDown(A, i, n);
    }
    for (i = n-1; i > 0; i--) {
        swap(A[0], A[i]);
        maxHeapFixDown(A, 0, i);
    }
}

int main() {
    int num[10] = {41, 34, 89, 22, 6, 91, 53, 29, 66, 30};
    int i;

    printf("\nBefore sort: ");
    for (i = 0; i < 10; i++) {
        printf("%3d", num[i]);
    }

    select_sort(num, 10);

    printf("\nAfter  sort: ");
    for (i = 0; i < 10; i++) {
        printf("%3d", num[i]);
    }
    printf("\n");

    return 0;
}

