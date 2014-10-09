#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

const int READER_NUM = 10;
pthread_rwlock_t rwlock;
pthread_mutex_t mutex;

void readerFunc(void) {
    int id = ((int)pthread_self()) % 10000;
    printf("Reader %4d is waiting\n", id);
    pthread_rwlock_rdlock(&rwlock);

    pthread_mutex_lock(&mutex);
    printf("  Reader %4d start reading ...\n", id);
    sleep(rand()%11);
    printf("  Reader %4d finish reading !\n", id);
    pthread_mutex_unlock(&mutex);

    pthread_rwlock_unlock(&rwlock);
}

void writerFunc(void) {
    int id = ((int)pthread_self()) % 10000;
    int i;
    for (i = 0; i < 4; i++) {
        printf("        Writer %4d is waiting\n", id);
        pthread_rwlock_wrlock(&rwlock);

        printf("          Writer %4d start writing ...\n", id);
        sleep(rand()%3);
        printf("          Writer %4d finish writing !\n", id);

        pthread_rwlock_unlock(&rwlock);

        sleep(rand()%3);
    }
}

int main(void) {
    pthread_t handle[READER_NUM+1];
    int i;

    pthread_rwlock_init(&rwlock, NULL);
    pthread_mutex_init(&mutex, NULL);

    // create 2 reader threads firstly
    for (i = 1; i < 2; i++) {
        pthread_create(&handle[i], NULL, (void*)readerFunc, NULL); 
    }
    // create the writer thread
    pthread_create(&handle[0], NULL, (void*)writerFunc, NULL); 

    sleep(2);

    // create other reader threads
    for (; i <= READER_NUM; i++) {
        pthread_create(&handle[i], NULL, (void*)readerFunc, NULL); 
    }

    for (i = 0; i <= READER_NUM; i++) {
        pthread_join(handle[i], NULL);
    }

    pthread_rwlock_destroy(&rwlock);
    pthread_mutex_destroy(&mutex);

    return 0;
}

