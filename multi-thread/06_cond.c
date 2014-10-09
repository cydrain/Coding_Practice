#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int g_nNum;
const int THREAD_NUM = 10;
pthread_mutex_t mutex;
pthread_cond_t cond;

void threadFunc(int* num) {
    sleep(1);
    g_nNum++;
    //sleep(1);
    printf("thread No.%d, global num %d\n", *num, g_nNum);
    pthread_cond_signal(&cond);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    g_nNum = 0;

    for (i = 0; i < THREAD_NUM; i++) {
        ret = pthread_create(&handle[i], NULL, (void*)threadFunc, &i); 
        if (ret != 0) {
            printf("Create thread %d error: %d\n", i, ret);
            exit(1);
        }
        else {
            printf("Create No.%d thread, id %ld\n", i, (long)handle[i]);
        }
        pthread_cond_wait(&cond, &mutex);
    }

    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(handle[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

