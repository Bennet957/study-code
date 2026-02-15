#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    // Pointer auf das argv-Array
    char **ptr = argv;
    for(int i = 0; i < argc; i++) {
        // Mit Pointer-Arithmetik: *(ptr + i) ist gleich wie ptr[i] oder argv[i]
        printf("Argument %d at address '%p': has content: %s (length: %zu)\n", 
               i, (void*)*(ptr + i), *(ptr + i), strlen(*(ptr + i)));
    }
    
    return 0;
}
