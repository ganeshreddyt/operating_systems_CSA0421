#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function executed by each thread
void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    printf("Thread %d is running\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i, result;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        result = pthread_create(&threads[i], NULL, thread_function, (void *)&thread_args[i]);
        if (result) {
            printf("Error creating thread %d: %d\n", i, result);
            exit(-1);
        }
    }

    // Wait for threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}