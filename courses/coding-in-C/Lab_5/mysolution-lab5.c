#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

    **pp=42; // modify x via pp
    printf("x after modification via pp = %d\n", x); 
    return 0;
}
