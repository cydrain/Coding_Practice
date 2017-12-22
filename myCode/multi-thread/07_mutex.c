#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int g_nNum;
const int THREAD_NUM = 10;
pthread_mutex_t mutex;

void threadFunc(int* num) {
    sleep(1);
    g_nNum++;
    //sleep(1);
    printf("thread No.%d, global num %d\n", *num, g_nNum);
    pthread_mutex_unlock(&mutex);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;

    pthread_mutex_init(&mutex, NULL);

    g_nNum = 0;

    for (i = 0; i < THREAD_NUM; i++) {
        pthread_mutex_lock(&mutex);
        ret = pthread_create(&handle[i], NULL, (void*)threadFunc, &i); 
        if (ret != 0) {
            printf("Create thread %d error: %d\n", i, ret);
            exit(1);
        }
        else {
            printf("Create No.%d thread, id %ld\n", i, (long)handle[i]);
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(handle[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);

    return 0;
}

