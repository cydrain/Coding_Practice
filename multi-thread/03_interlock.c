#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int g_nLoginCount;
const int THREAD_NUM = 10;

void threadFunc(void) {
    sleep(1);
    g_nLoginCount++;
    //sleep(1);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;
    int num = 20;

    for (num = 1; num <= 10; num++) {
        g_nLoginCount = 0;

        for (i = 0; i < THREAD_NUM; i++) {
            ret = pthread_create(&handle[i], NULL, (void*)threadFunc, NULL); 
            if (ret != 0) {
                printf("Create thread %d error: %d\n", i, ret);
                exit(1);
            }
            else {
                printf("Iterate %d: Create No.%d thread, id %ld\n",
                       num, i, (long)handle[i]);
            }
        }

        for (i = 0; i < THREAD_NUM; i++) {
            pthread_join(handle[i], NULL);
        }
        //pthread_join(handle[THREAD_NUM-1], NULL);

        printf("After %d accounts login, login record num is %d\n\n",
               THREAD_NUM, g_nLoginCount);
    }

    return 0;
}

