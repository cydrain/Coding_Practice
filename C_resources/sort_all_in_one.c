//#include <iostream>
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

// 8. count sort
/*
 *  算法的步骤如下：
 *   1、找出待排序的数组中最大和最小的元素
 *   2、统计数组中每个值为t的元素出现的次数，存入数组C的第t项
 *   3、对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
 *   4、反向填充目标数组：将每个元素t放在新数组的第C(t)项，每放一个元素就将C(t)减去1
 */
int getMaxNumber(int a[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

void count_sort(int a[], int b[], int n, int k) {
    int i;
    int* c = new int[k+1];

    for (i = 0; i < k; i++) {
        c[i] = 0;
    }        
    for (i = 0; i < n; i++) {
        c[a[i]]++;
    }        

    for (i = 1; i <= k; i++) {
        c[i] += c[i-1];
    }        

    for (i = n - 1; i >= 0; i--) {
        //c[a[i]]-1 就代表小于等于元素A[i]的元素个数，就是A[i]在B的位置
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    
    delete[] c;
}



// 9. index sort
// d为数据长度
/*
void radixSorting(int[] arr, int d) {        
    //arr = countingSort(arr, 0);
    for (int i = 0; i < d; i++) {
        arr = countingSort(arr, i); // 依次对各位数字排序（直接用计数排序的变体）
        print(arr,i+1,d);
    }
}

// 把每次按位排序的结果打印出来
void print(int[] arr,int k,int d) {
    if(k==d)
        System.out.println("最终排序结果为：");
    else
        System.out.println("按第"+k+"位排序后，结果为：");

    for (int t : arr) {
        System.out.print(t + " ");
    }

    System.out.println();
}

// 利用计数排序对元素的每一位进行排序
int[] countingSort(int[] arr, int index) {
    int k = 9;
    int[] b = new int[arr.length];
    int[] c = new int[k + 1]; //这里比较特殊：数的每一位最大数为9        

    for (int i = 0; i < k; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < arr.length; i++) {
        int d = getBitData(arr[i], index);
        c[d]++;
    }

    for (int i = 1; i <= k; i++) {
        c[i] += c[i - 1];
    }

    for (int i = arr.length - 1; i >= 0; i--) {
        int d = getBitData(arr[i], index);
        b[c[d] - 1] = arr[i];//C[d]-1 就代表小于等于元素d的元素个数，就是d在B的位置
        c[d]--;
    }

    return b;
}

// 获取data指定位的数
int getBitData(int data, int index) {
    while (data != 0 && index > 0) {
        data /= 10;
        index--;
    }

    return data % 10;
}
*/


// 10. bucket sort
/*
void insert(int[] a, int index, int x) {
    // 元素插入数组a[0:index-1]
    int i;
    for (i = index - 1; i >= 0 && x < a[i]; i--) {
        a[i + 1] = a[i];
    }
    a[i + 1] = x;
}

// 插入排序
void insertSort(int[] a) {
    int n = a.length;
    for (int i = 1; i < n; i++) {
        int p = a[i];
        insert(a, i, p);
    }
}

void bucketSort(int[] a) {
    int M = 10; // 11个桶
    int n = a.length;
    int[] bucketA = new int[M]; // 用于存放每个桶中的元素个数
    // 构造一个二维数组b，用来存放A中的数据,这里的B相当于很多桶，B[i][]代表第i个桶
    int[][] b = new int[M][n];
    int i, j;

    for (i = 0; i < M; i++)
        for (j = 0; j < n; j++)
            b[i][j] = 0;

    int data, bucket;

    for (i = 0; i < n; i++) {
        data = a[i];
        bucket = data / 10;

        // B[0][]中存放A中进行A[i]/10运算后高位为0的数据，同理B[1][]存放高位为1的数据
        b[bucket][bucketA[bucket]] = a[i];

        // 用来计数二维数组中列中数据的个数，也就是桶A[i]中存放数据的个数
        bucketA[bucket]++;
    }

    System.out.println("每个桶内元素个数：");
    for (i = 0; i < M; i++) {
        System.out.print(bucketA[i] + " ");
    }

    System.out.println();

    System.out.println("数据插入桶后，桶内未进行排序前的结果为：");

    for (i = 0; i < M; i++) {
        for (j = 0; j < n; j++)
            System.out.print(b[i][j] + " ");
        System.out.println();
    }

    System.out.println("对每个桶进行插入排序，结果为：");

    // 下面使用直接插入排序对这个二维数组进行排序,也就是对每个桶进行排序

    for (i = 0; i < M; i++) {
        // 下面是对具有数据的一列进行直接插入排序，也就是对B[i][]这个桶中的数据进行排序
        if (bucketA[i] != 0) {
            // 插入排序
            for (j = 1; j < bucketA[i]; j++) {
                int p = b[i][j];
                int k;
                for (k = j - 1; k >= 0 && p < b[i][k]; k--) {
                    assert(k == -1);
                    b[i][k + 1] = b[i][k];
                }

                b[i][k + 1] = p;
            }
        }
    }

    // 输出排序过后的顺序
    for (i = 0; i < 10; i++) {
        if (bucketA[i] != 0) {
            for (j = 0; j < bucketA[i]; j++) {
                System.out.print(b[i][j] + " ");
            }
        }
    }
}
*/

int main() {
    int num[10] = {41, 34, 89, 22, 6, 91, 53, 29, 66, 30};
    int sorted[10];
    int i;

    printf("\nBefore sort: ");
    for (i = 0; i < 10; i++) {
        printf("%3d", num[i]);
    }

    //select_sort(num, 10);
    count_sort(num, sorted, 10, getMaxNumber(num, 10));

    printf("\nAfter  sort: ");
    for (i = 0; i < 10; i++) {
        printf("%3d", sorted[i]);
    }
    printf("\n");

    return 0;
}

