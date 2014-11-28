/*
 * You have a sorted array containing the age of every person on Earth. 
 * [0, 0, 0, 0, ..., 1, 1, ..., 28, 28, ..., 110, ...] 
 * Find out how many people have each age.
 */

#include <iostream>
using namespace std;

int findRightMostIndex(int A[], int n, int target) {
    int l = 0, r = n-1, m;
    if (A[r] == target) return r;

    while (l < r) {
        m = l + (r-l)/2;
        if (A[m] == target) {
            if (A[m+1] != target) {
                return m;
            }
            else {
                l = m + 1;
            }
        }
        else if (A[m] > target) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return (A[l] == target ? l : -1);
}

int main(void) {
    int population[] = {2,2,2,2,2,2,2,2,
                        3,3,3,3,
                        5,5,5,5,5,5,5,5,5,5,5,
                        6,7,7,7,7,7,7,7,
                        8,8,8,8,9,9};
    int index[10], count[10];
    int i;

    for (i = 0; i < 10; i++) {
        index[i] = findRightMostIndex(population, sizeof(population), i);
        if (index[i] == -1 && i > 0) {
            index[i] = index[i-1];
        }
        cout << index[i] << endl;
    }

    for (i = 9; i > 0; i--) {
        count[i] = index[i] - index[i-1];
    }
    count[0] = index[0] + 1;

    for (i = 0; i < 10; i++) {
        cout << count[i] << " ";
    }

    return 0;
}
