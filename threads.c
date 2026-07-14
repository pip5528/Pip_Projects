#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *crap(void *arg) {
    while (1) {
    sleep(1);
    printf("What a load of crap!\n");
    return NULL;
    }
}

void *stuff(void *arg) {
    while (1) {
    sleep(1);
    printf("Stuff!\n");
    return NULL;
    }
}


int main(void) {

    
pthread_t thread1;
pthread_create(&thread1, NULL, crap, NULL);
pthread_t thread2;
pthread_create(&thread2, NULL, stuff, NULL);
crap(NULL);
stuff(NULL);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

return 0;
}

