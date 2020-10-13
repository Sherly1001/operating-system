#include <stdio.h>
#include <stdlib.h>


void prt(int *a, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

void tryi(int *a, char *c, int n, int i) {
    for (int j = 0; j < n; ++j) {
        if (c[j]) continue;
        a[i] = j + 1;
        if (i == n - 1) prt(a, n);
        else {
            c[j] = 1;
            tryi(a, c, n, i + 1);
            c[j] = 0;
        }
    }
}

void sher(int n) {
    if (n < 1) return;

    int *a = malloc(n * sizeof(int));
    char *c = calloc(n, sizeof(char));

    for (int i = 0; i < n; ++i) a[i] = i + 1;
    
    tryi(a, c, n, 0);
    
    free(a);
    free(c);
}

int main() {
    int n = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    sher(n);
}