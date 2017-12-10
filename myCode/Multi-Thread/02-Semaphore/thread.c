#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

const int THREAD_NUM = 10;
volatile int g_nNum;
sem_t sem;

void* threadFunc(void* num) {
    sleep(2);
    g_nNum++;
    sleep(5);
    printf("thread No.%d, global num %d\n", *(int*)num, g_nNum);
    sem_post(&sem);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;

    sem_init(&sem, 0, 0);

    g_nNum = 0;

    for (i = 0; i < THREAD_NUM; i++) {
        ret = pthread_create(&handle[i], NULL, threadFunc, &i);
        if (ret != 0) {
            printf("Create thread %d error: %d\n", i, ret);
            exit(1);
        } else {
            printf("Create No.%d thread, id %ld\n", i, (long)handle[i]);
        }
        sem_wait(&sem);
    }

    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(handle[i], NULL);
    }

    sem_destroy(&sem);

    return 0;
}
