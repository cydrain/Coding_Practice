#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

const int PRODUCT_NUM = 10;
pthread_mutex_t mutex;
sem_t sem_empty, sem_full;
int g_idx;

void ConsumerFunc(void) {
    volatile int flag = 1;
    while (flag) {
        sem_wait(&sem_full);

        pthread_mutex_lock(&mutex);
        printf("     ===>%d\n", g_idx);
        if (g_idx == PRODUCT_NUM) {
            flag = 0;
        }
        sleep(rand()%3);
        //sleep(2);
        pthread_mutex_unlock(&mutex);

        sem_post(&sem_empty);
        //sleep(rand()%2);
    }
}

void ProducerFunc(void) {
    int i;
    for (i = 1; i <= PRODUCT_NUM; i++) {
        sem_wait(&sem_empty);

        pthread_mutex_lock(&mutex);
        g_idx = i;
        printf("%d===>\n", g_idx);
        sleep(rand()%3);
        //sleep(1);
        pthread_mutex_unlock(&mutex);

        sem_post(&sem_full);
        //sleep(rand()%2);
    }
}

int main(void) {
    pthread_t p_tid, c_tid;

    g_idx = 0;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_empty, 0, 1);
    sem_init(&sem_full, 0, 0);

    pthread_create(&p_tid, NULL, (void*)ProducerFunc, NULL);
    pthread_create(&c_tid, NULL, (void*)ConsumerFunc, NULL);

    pthread_join(p_tid, NULL);
    pthread_join(c_tid, NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    return 0;
}

