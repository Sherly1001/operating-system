#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = malloc(sizeof(int));
    printf("Value of pointer a: %p\nEnter a: ", a);
    scanf("%d", a);
    getchar();
    getchar();
    return 0;
}

// result

// -> ./ex2-p1
// Value of pointer a: 0x7fffde64e260
// Enter a: 1001