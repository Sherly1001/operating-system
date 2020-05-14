#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 0;
int turn = 0;

int s1 = 0, s2 = 0;

void *sher1(void *args) {
    while (1) {
        s1 = 1;
        while (s2);
        while (turn == 2);
        turn = 1;
        ++n;
        printf("%d\n", n);
        turn = 0;
        s1 = 0;
    }
}

void *sher2(void *args) {
    while (1) {
        s2 = 1;
        while (s1);
        while (turn == 1);
        turn = 2;
        ++n;
        turn = 0;
        s2 = 0;
    }
}

int main() {
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, sher1, NULL);
    pthread_create(&tid2, NULL, sher2, NULL);

    pthread_join(tid2, NULL);
}
