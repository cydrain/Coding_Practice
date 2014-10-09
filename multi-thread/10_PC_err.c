#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

const int PRODUCT_NUM = 10;
const int BUFFER_SIZE = 4;
int buffer[BUFFER_SIZE];
int rd_idx, wr_idx, g_num;
pthread_mutex_t mutex;
sem_t sem_empty, sem_full;

void ConsumerFunc(void) {
    int id = ((int)pthread_self()) % 10000;
    volatile int flag = 1;
    while (flag) {
        sem_wait(&sem_full);

        pthread_mutex_lock(&mutex);
        printf("     (%d)===>%d(%d)\n",
               rd_idx, buffer[rd_idx], id);
        if (buffer[rd_idx] == PRODUCT_NUM) {
            pthread_mutex_unlock(&mutex);
            return;
        }
        rd_idx = (rd_idx+1)%BUFFER_SIZE;
        //sleep(rand()%5);
        pthread_mutex_unlock(&mutex);
        sleep(2);

        sem_post(&sem_empty);
        //sleep(rand()%2);
    }
}

void ProducerFunc(void) {
    int i;
    for (i = 1; i <= PRODUCT_NUM; i++) {
        sem_wait(&sem_empty);

        pthread_mutex_lock(&mutex);
        buffer[wr_idx] = i;
        printf("%d===>(%d)\n", i, wr_idx);
        wr_idx = (wr_idx+1)%BUFFER_SIZE;
        //sleep(rand()%2);
        sleep(1);
        pthread_mutex_unlock(&mutex);

        sem_post(&sem_full);
        //sleep(rand()%2);
    }
}

int main(void) {
    pthread_t p_tid;
    pthread_t c_tid1, c_tid2;

    rd_idx = wr_idx = 0;
    g_num = 0;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_empty, 0, 1);
    sem_init(&sem_full, 0, 0);

    pthread_create(&p_tid, NULL, (void*)ProducerFunc, NULL);
    pthread_create(&c_tid1, NULL, (void*)ConsumerFunc, NULL);
    //pthread_create(&c_tid2, NULL, (void*)ConsumerFunc, NULL);

    pthread_join(p_tid, NULL);
    pthread_join(c_tid1, NULL);
    //pthread_join(c_tid2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}

