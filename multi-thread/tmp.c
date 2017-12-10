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
    printf("Consumer thread %d is waiting for the semaphore\n",
           (int)pthread_self());
    sleep(1);
    sem_wait(&sem_full);
    printf("Consumer thread %d get semaphore\n", (int)pthread_self());
    sleep(1);
    printf("Consumer thread %d is waiting for the semaphore again\n",
           (int)pthread_self());
    sem_wait(&sem_full);

    printf("Consumer thread %d get semaphore\n", (int)pthread_self());
}

void ProducerFunc(void) {
    printf("Producer thread %d is waiting for the semaphore\n",
           (int)pthread_self());
    sleep(1);
    sem_wait(&sem_full);

    printf("Producer thread %d get semaphore\n", (int)pthread_self());
}

int main(void) {
    pthread_t p_tid, c_tid;
    char c;

    sem_init(&sem_full, 0, 0);

    pthread_create(&p_tid, NULL, (void*)ProducerFunc, NULL);
    //pthread_create(&c_tid, NULL, (void*)ConsumerFunc, NULL);

    while (gets(&c)) {
        if (c != 'y') {
            printf("Get %d, Please input 'y'\n", c);
        }
        else {
            sem_post(&sem_full);
            break;
        }
    }

    sleep(3);
    pthread_join(p_tid, NULL);
    //pthread_join(c_tid, NULL);
    return 0;
}

