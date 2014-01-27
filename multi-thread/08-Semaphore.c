#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

volatile int g_nNum;
const int THREAD_NUM = 10;
sem_t sem;

void ThreadFunc(void* num) {
    int tId = *(int*)num;
    sleep(1);
    g_nNum++;
    //sleep(1);
    printf("Thread No. %d, global num %d\n", tId, g_nNum);
    sem_post(&sem);
}

int main(void) {
    pthread_t handle[THREAD_NUM];
    int i, ret;

    g_nNum = 0;
    sem_init(&sem, 0, 1);

    for (i = 0; i < THREAD_NUM; i++) {
        sem_wait(&sem);
        ret = pthread_create(&handle[i], NULL, (void*)ThreadFunc, &i);
        if (ret != 0) {
            printf("Create thread error: %d\n", ret);
            exit(1);
        }
    }

    pthread_join(handle[THREAD_NUM-1], NULL);
    return 0;
}

