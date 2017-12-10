#include <stdio.h>
#include <malloc.h>

char* mallocPage(void) {
    char* ptr = NULL, *ret = NULL;
    char** addr = NULL;

    ptr = malloc((0x1 << 11) * sizeof(char));
    if (ptr == NULL) {
        printf("malloc fail!\n");
        return NULL;
    }
    
    ret = (char*)(((long)ptr + (0x1 << 10)) & ((~0) << 10));
    addr = (char**)((long)ret - sizeof(char*));
    *addr = ptr;

    printf("malloc = %p, addr = %p, ret = %p\n", ptr, addr, ret);
    return ret;
}

void freePage(char* ptr) {
    char** addr = NULL;
    addr = (char**)((long*)ptr - 1);
    free(*addr);
}

int main(void) {
    int i;
    char* ptr;
    for (i = 0; i < 5; i++) {
        ptr = mallocPage();
        freePage(ptr);
    }
    return 0;
}
