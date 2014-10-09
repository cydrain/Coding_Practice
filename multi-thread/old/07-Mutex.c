#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int g_nNum;
const int THREAD_NUM = 10;
pthread_mutex_t mutex;

void ThreadFunc(void* num) {
    int tId = *(int*)num;
    sleep(1);
    g_nNum++;
    //sleep(1);
    printf("Thread No. %d, global num %d\n", tId, g_nNum);
    pthread_mutex_unlock(&mutex);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;

    g_nNum = 0;
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < THREAD_NUM; i++) {
        pthread_mutex_lock(&mutex);
        ret = pthread_create(&handle[i], NULL, (void*)ThreadFunc, &i);
        if (ret != 0) {
            printf("Create thread error: %d\n", ret);
            exit(1);
        }
    }

    pthread_join(handle[THREAD_NUM-1], NULL);
    return 0;
}

