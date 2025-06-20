q1) write a C program that creates two threads.each threads should print a message indicating it is running 
should wait for both threads to finish before exiting


#include <stdio.h>
#include <pthread.h>

void* run(void* arg) {
    printf("Thread %d is running\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, run, &id1);
    pthread_create(&t2, NULL, run, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished\n");
    return 0;
}


q2) write a program to create 5 threads each thread should print its thread ID and then exit .the main thread should join all thread 
and print a completion message

#include <stdio.h>
#include <pthread.h>

void* print_id(void* arg) {
    printf("Thread ID: %d\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5];

    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, print_id, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}


q3) write aprogram that creates a thread which prints numbers from 1 to 10
with a 1-second delay between each number .the main theread should wait for this thread to finish

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* count(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, count, NULL);
    pthread_join(t, NULL);
    printf("Counting done.\n");
    return 0;
}


q4).create two thread where one thread increments a global counter 100 and the other thread decrements the 
same counter 100 times print the value of the counter after both threads finish

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;
}


q5) implement a thread function that takes an integer argument,square it, and returns the result to the main thread 
using pthread_exit and pthread_join

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    pthread_exit(result);
}

int main() {
    pthread_t t;
    int num = 7;
    void* res;

    pthread_create(&t, NULL, square, &num);
    pthread_join(t, &res);

    printf("Square of %d is %d\n", num, *(int*)res);
    free(res);
    return 0;
}
