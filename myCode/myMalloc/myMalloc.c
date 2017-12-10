/*
 * Realize simple malloc/free in a given block of memory
 *
 *   +-------------------------------------------------
 *   |                                               |
 *   |                                               |
 *   |                                               |
 *   |                                               |
 *   |                  Memory  Pool                 |
 *   |                                               |
 *   |                                               |
 *   |                                               |
 *   |                                               |
 *   +-----------------------------------------------+
 *   | mem_node1 | mem_node2 | mem_node3 | mem_node4 |
 *   +-----------------------------------------------+
 *   | mem_node5 | mem_node6 | mem_node7 | mem_node8 |
 *   +-----------------------------------------------+
 *   |  ... ...  |  ... ...  |  ... ...  |  ... ...  |
 *   +-----------------------------------------------+
 *   |  ... ...  | mem_node98| mem_node99|mem_node100|
 *   +-----------------------------------------------+
 *   |                                               |
 *   +-----------------------------------------------+
 *
 * */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

#define MEM_SIZE    10240
#define NODE_NUM    100

#define _DEBUG_     0

typedef struct {
    short used;
    short size;
    void* start_addr;
} mem_node;

char mem[MEM_SIZE];
mem_node* node;

void init(void)
{
    int i;
    
    memset(mem, '\0', MEM_SIZE);
    
    node = (mem_node*)(mem + MEM_SIZE - NODE_NUM * sizeof(mem_node));
    for (i = 0; i < NODE_NUM; i++) {
        node[i].used = 0;
        node[i].size = 0;
        node[i].start_addr = NULL;
    }

    node[0].start_addr = mem;
    node[0].size = MEM_SIZE - NODE_NUM * sizeof(mem_node);
}

void showMemNode(void)
{
    int i;

    for (i = 0; i < NODE_NUM; i++) {
        printf("Node %02d: used %d, size %4d, start_addr %p\n",
                i, node[i].used, node[i].size, node[i].start_addr);
    }
}

void* myMalloc(size_t size)
{
    int i, j;

    for (i = 0; i < NODE_NUM; i++) {
        if (node[i].used == 0 && node[i].size >= size) {
            if (node[i].size > size) {
                for (j = 0; j < NODE_NUM; j++) {
                    if (node[j].used == 0 && node[j].size == 0) {
                        node[j].size = node[i].size - size;
                        node[j].start_addr = node[i].start_addr + size;
                        break;
                    }
                }
                if (j == NODE_NUM) {
                    printf("Have reached the max memory nodes %d limits!\n", NODE_NUM);
                    return NULL;
                }
            }

            node[i].used = 1;
            node[i].size = size;

#if _DEBUG_
            printf("malloc %d, %p\n", node[i].size, node[i].start_addr);
#endif
            return node[i].start_addr;
        }
    }

    printf("Cannot find enough memory piece %d!\n", size);
    //showMemNode();

    return NULL;
}

void myFree(void* ptr)
{
    int i, j;

    for (i = 0; i < NODE_NUM; i++) {
        if (node[i].used == 1 && node[i].start_addr == ptr) {
            node[i].used = 0;
            break;
        }
    }
    if (i == NODE_NUM) {
        printf("Invalid free ptr %p!\n", ptr);
        return;
    }

#if _DEBUG_
    printf("free %d, %p\n", node[i].size, node[i].start_addr);
#endif

    /* merge node[i] backward */
    for (j = 0; j < NODE_NUM; j++) {
        if (node[j].used == 0 &&
            node[j].start_addr == node[i].start_addr + node[i].size) {
            node[i].size += node[j].size;

            node[j].size = 0;
            node[j].start_addr = NULL;
            break;
        }
    }

    /* merge node[i] forward */
    for (j = 0; j < NODE_NUM; j++) {
        if (node[j].used == 0 &&
            node[i].start_addr == node[j].start_addr + node[j].size) {
            node[j].size += node[i].size;

            node[i].size = 0;
            node[i].start_addr = NULL;
        }
    }
}


#define TEST_NUM        100000
#define ARRAY_NUM       100
#define MAX_MALLOC_SIZE 200
int main(void)
{
    int i, idx;
    void* ptr[ARRAY_NUM];

    init();

    for (i = 0; i < ARRAY_NUM; i++) {
        ptr[i] = NULL;
    }

    for (i = 0; i < TEST_NUM; i++) {
        idx = random() % ARRAY_NUM;
        if (ptr[idx] == NULL) {
            ptr[idx] = myMalloc(random() % MAX_MALLOC_SIZE + 1);
        } else {
            myFree(ptr[idx]);
            ptr[idx] = NULL;
        }
    }

    showMemNode();
    
    return 0;
}
