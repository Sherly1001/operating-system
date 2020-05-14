#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 0, m = 0;

pthread_mutex_t mut_n = PTHREAD_MUTEX_INITIALIZER;

void *sher1(void *args) {
    while (1) {
        ++m;

        pthread_mutex_lock(&mut_n);
        ++n;
        pthread_mutex_unlock(&mut_n);
    }
}

void *sher2(void *args) {
    while (1) {
        ++m;

        pthread_mutex_lock(&mut_n);
        ++n;
        printf("n: %d, m: %d\n", n, m);
        pthread_mutex_unlock(&mut_n);
    }
}

int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, sher1, NULL);
    pthread_create(&tid2, NULL, sher2, NULL);

    pthread_join(tid2, NULL);
}