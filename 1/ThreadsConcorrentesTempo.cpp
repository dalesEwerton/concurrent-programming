#include <cstdio>
#include <iostream>
#include <pthread.h>
#include <time.h>

long int counter = 0;

void* run(void* args){
    long int my_id;
    long int j;

    my_id = (long int) args;

    for (j = 0; j < 1e7; j++) {
        counter++;
    }

   // printf("my_id= %ld j=%ld counter=%ld \n", my_id,j, counter);
}

int main(int argc, char *argv[]) {
    int i;
    pthread_t pthreads[30000];

    clock_t clock1;
    clock1 = clock();
    for (i = 0; i < 3; i++) {
        pthread_create(&pthreads[i], NULL, &run, (void*) i);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(pthreads[i], NULL);
    }

    printf("Tempo para 3 threads: %fms\n", ((clock() - clock1) / (double) CLOCKS_PER_SEC));
    printf("\n\n");

    clock_t clock2;
    clock2 = clock();
    for (i = 0; i < 30; i++) {
        pthread_create(&pthreads[i], NULL, &run, (void*) i);
    }

    for (i = 0; i < 30; i++) {
        pthread_join(pthreads[i], NULL);
    }

    printf("Tempo para 30 threads: %fms\n", ((clock() - clock2) / (double) CLOCKS_PER_SEC));
    printf("\n\n");

    clock_t clock3;
    clock3 = clock();
    for (i = 0; i < 300; i++) {
        pthread_create(&pthreads[i], NULL, &run, (void*) i);
    }

    for (i = 0; i < 300; i++) {
        pthread_join(pthreads[i], NULL);
    }

    printf("Tempo para 300 threads: %fms\n", ((clock() - clock3) / (double) CLOCKS_PER_SEC));
    printf("\n\n");

    clock_t clock4;
    clock4 = clock();
    for (i = 0; i < 3000; i++) {
        pthread_create(&pthreads[i], NULL, &run, (void*) i);
    }

    for (i = 0; i < 3000; i++) {
        pthread_join(pthreads[i], NULL);
    }

    printf("Tempo para 3000 threads: %fms\n", ((clock() - clock4) / (double) CLOCKS_PER_SEC));
    printf("\n\n");

    clock_t clock5;
    clock5 = clock();
    for (i = 0; i < 30000; i++) {
        pthread_create(&pthreads[i], NULL, &run, (void*) i);
    }

    for (i = 0; i < 30000; i++) {
        pthread_join(pthreads[i], NULL);
    }

    printf("Tempo para 30000 threads: %fms\n", ((clock() - clock5) / (double) CLOCKS_PER_SEC));
    printf("\n\n");

    return 0;
}