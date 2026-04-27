#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    
    for(int i = 0; i < argc; i++) {
        printf("Argument %d at address '%p': has content: %s (length: %d)\n", i, (void*)argv[i], argv[i], strlen(argv[i]));
    }
    
    return 0;
}
