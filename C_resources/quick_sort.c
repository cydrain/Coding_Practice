#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quicksort(int array[], int start, int end)
{
    int i, j;
    int pilot;
    int tmp;

    if (start >= end) return;

    pilot = array[start];
    i = start+1;
    j = end;

    while (i < j) {
        while (array[i] < pilot) {
            i++;
        }

        while (array[j] > pilot) {
            j--;
        }

        if (i < j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    tmp = array[start];
    array[start] = array[j];
    array[j] = tmp;

    quicksort(array, start, j-1);
    quicksort(array, j+1, end);
}

int main() {
    int n;
    char string[100];
    int array[10];
    char* ptr;
    int i = 0;

    printf("Please input the record num: ");
    scanf("%d", &n);
    getchar();

    gets(string);

    ptr = strtok(string, " ");
    array[i++] = atoi(ptr);
    while (i < n) {
        ptr = strtok(NULL, " ");
        array[i++] = atoi(ptr);
    }

    quicksort(array, 0, n-1);

    printf("n=%d\n", n);
    for (i=0; i<n; i++) {
        printf("array[%d]=%d\n", i, array[i]);
    }

    return 0;
}

