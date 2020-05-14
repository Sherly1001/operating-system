#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = NULL;
    scanf("%p", &a); // enter a address from process 1
    printf("a: %p\n*a: %d\n", a, *a);
    // change *a
    *a = 10; // err
    return 0;
}

// result

// -> ./ex2-p2
// 0x7fffde64e260
// [1]    1027 segmentation fault (core dumped)  ./ex2-p2 