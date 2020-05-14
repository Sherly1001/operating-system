#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex_a = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_a = PTHREAD_COND_INITIALIZER;

pthread_mutex_t mutex_b = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_b = PTHREAD_COND_INITIALIZER;

int a = 0, b = 0;

void *sher1(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex_a);
        while (b + 100 <= a) pthread_cond_wait(&cond_a, &mutex_a);
        if (a >= b) pthread_cond_signal(&cond_b);
        ++a;
        pthread_mutex_unlock(&mutex_a);
    }
}

void *sher2(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex_b);
        while (b >= a) pthread_cond_wait(&cond_b, &mutex_b);
        if (b + 100 >= a) pthread_cond_signal(&cond_a);
        ++b;
        pthread_mutex_unlock(&mutex_b);
    }
}

void *sher3(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex_a);
        pthread_mutex_lock(&mutex_b);
        if (a < b) printf("a: %d, b: %d, a < b\n", a, b);
        if (a > b + 100) printf("a: %d, b: %d, a > b + 100\n", a, b);
        pthread_mutex_unlock(&mutex_a);
        pthread_mutex_unlock(&mutex_b);
    }
}

int main() {
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;

    pthread_create(&tid1, NULL, sher1, NULL);
    pthread_create(&tid2, NULL, sher2, NULL);
    pthread_create(&tid3, NULL, sher3, NULL);

    pthread_join(tid3, NULL);
}