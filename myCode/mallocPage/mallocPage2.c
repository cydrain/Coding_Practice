#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef unsigned long ulong;

#define PAGE_SIZE 1024
#define PAGE_MASK (~((ulong)0) << 10)

void* mallocPage(void)
{
    void *org_ptr = NULL, *page_ptr = NULL;
    ulong *addr_ptr = NULL;

    org_ptr = malloc(PAGE_SIZE * 2);
    if (org_ptr == NULL) {
        printf("No enough memory!\n");
        return NULL;
    }

    page_ptr = (void*)(((ulong)org_ptr + PAGE_SIZE) & PAGE_MASK);
    addr_ptr = (ulong*)page_ptr - 1;
    *addr_ptr = (ulong)org_ptr;
    printf("org_ptr = %p, addr_ptr = %p, *addr_ptr = %x, page_ptr = %p\n",
            org_ptr, addr_ptr, *addr_ptr, page_ptr);
    
    return page_ptr;
}

void freePage(void* ptr)
{
    void *org_ptr = NULL;

    if (ptr == NULL) {
        printf("Invalid ptr!\n");
        return;
    }
    
    org_ptr = (void*)*((ulong*)ptr - 1);
    printf("Free %p\n", org_ptr);

    free(org_ptr);
}

int main(void)
{
    int i;
    void* ptr[5];
    for (i = 0; i < 5; i++) {
        ptr[i] = mallocPage();
    }
    for (i = 0; i < 5; i++) {
        freePage(ptr[i]);
    }
    return 0;
}
