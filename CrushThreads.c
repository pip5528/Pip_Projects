#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep()

// Define a structure to pass custom arguments to the thread function
typedef struct {
    int id;
    const char* message;
} thread_args_t;

/**
 * @brief The main function executed by each thread.
 * 
 * @param arg Pointer to the argument structure passed from main.
 * @return void* NULL, as this is a simple worker function.
 */
void* thread_function(void* arg) {
    // Cast the void pointer back to our custom structure
    thread_args_t* args = (thread_args_t*)arg;

    printf("Thread %d: Starting work...\n", args->id);
    
    // Simulate doing some work by sleeping
    sleep(1 + (args->id % 2)); // Sleep time varies based on ID
    
    printf("Thread %d: %s\n", args->id, args->message);

    // Free the memory allocated for arguments when done
    free(arg); 
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    void* return_val;

    printf("Main: Starting multithreading example.\n\n");

    // --- Setup Arguments for Thread 1 ---
    thread_args_t* args1 = (thread_args_t*)malloc(sizeof(thread_args_t));
    if (args1 == NULL) return 1; // Check allocation

    args1->id = 1;
    args1->message = "Task A completed its simulation.";

    // --- Setup Arguments for Thread 2 ---
    thread_args_t* args2 = (thread_args_t*)malloc(sizeof(thread_args_t));
    if (args2 == NULL) {
        free(args1);
        return 1;
    }

    args2->id = 2;
    args2->message = "Task B completed its simulation.";


    // 1. Create threads
    // pthread_create takes: pointer to thread ID, attributes (NULL for default), function, argument
    if (pthread_create(&thread1, NULL, thread_function, (void*)args1) != 0) {
        perror("Error creating thread 1");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, thread_function, (void*)args2) != 0) {
        perror("Error creating thread 2");
        exit(EXIT_FAILURE);
    }

    printf("Main: Threads successfully created. Waiting for them to finish...\n\n");


    // 2. Wait for threads to completion (Joining)
    // pthread_join blocks the main thread until the target thread exits its function.
    pthread_join(thread1, &return_val);
    printf("Main: Thread 1 has finished execution.\n");

    pthread_join(thread2, &return_val);
    printf("Main: Thread 2 has finished execution.\n\n");


    printf("Main: All threads have completed. Exiting program safely.\n");

    return 0;
}
