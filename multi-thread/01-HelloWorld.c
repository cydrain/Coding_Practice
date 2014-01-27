#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void ThreadFunc(void) {
    // pthread_self() 返回调用线程的线程标识符id
    // typedef unsigned long int pthread_t;
    int i;
    for (i = 0; i < 5; i++) {
        printf("Thread with ID %ld say: Hello World!\n", (long int)pthread_self());
    }
}

int main(void) {
    const int THREAD_NUM = 5;
    pthread_t handle[THREAD_NUM];
    int i, ret;
    for (i = 0; i < THREAD_NUM; i++) {
        ret = pthread_create(&handle[i], NULL, (void*)ThreadFunc, NULL);
        if (ret != 0) {
            printf("Create thread error: %d\n", ret);
            exit(1);
        }
        else {
            printf("Create thread with ID %ld\n", (long int)handle[i]);
            
            //pthread_detach() 相当于让线程后台运行，当它结束时，所有资源将被释放，不需要等待我们去释放
            //pthread_detach(handle[i]);
        }
    }

    //pthread_join()是一个线程阻塞的函数，调用它的函数将一直等到被等待的线程结束为止
    // 等待最后一个线程结束
    pthread_join(handle[THREAD_NUM-1], NULL);
    return 0;
}

