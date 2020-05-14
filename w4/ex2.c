#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x = 0, y = 1;
void *sher1(void *args) {
    while (1) {
        x = y + 1;
        printf("%d ", x);
    }
}

void *sher2(void *args) {
    while (1) {
        y = 2;
        y *= 2;
    }
}

int main() {
    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1, NULL, sher1, NULL);
    pthread_create(&tid2, NULL, sher2, NULL);

    pthread_join(tid1, NULL);
}