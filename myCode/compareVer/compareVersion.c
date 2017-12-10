#include <stdio.h>
#include <string.h>

int compareVersion(char* version1, char* version2) {
    char *p1 = version1, *p2 = version2;
    int v1, v2;
    while (p1 && p2) {
        v1 = atoi(strsep(&p1, "."));
        v2 = atoi(strsep(&p2, "."));
        printf("v1=%d, v2=%d\n", v1, v2);
        if (v1 < v2) return -1;
        if (v1 > v2) return 1;
    }
    return 0;
}

int main() {
    char v1[32] = {'1'};
    char v2[32] = {'0'};
    printf("result = %d\n", compareVersion(v1,v2));
    return 1;
}

