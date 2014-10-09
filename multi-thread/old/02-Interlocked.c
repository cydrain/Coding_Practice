#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int g_nLoginCount;
const int THREAD_NUM = 50;

void ThreadFunc(void) {
    sleep(1);
    g_nLoginCount++;
    sleep(1);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;
    int num = 20;

    while (num--) {
        g_nLoginCount = 0;

        for (i = 0; i < THREAD_NUM; i++) {
            ret = pthread_create(&handle[i], NULL, (void*)ThreadFunc, NULL);
            if (ret != 0) {
                printf("Create thread error: %d\n", ret);
                exit(1);
            }
        }

        pthread_join(handle[THREAD_NUM-1], NULL);
        printf("After %d accounts login, recored count num is %d\n", THREAD_NUM, g_nLoginCount);
    }

    return 0;
}

