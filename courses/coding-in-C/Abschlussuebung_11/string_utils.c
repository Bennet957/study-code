#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

int main() {
    read_line_dynamic();

    return 0;
}


int custom_len(const char *ptr) {
    int length = 0;
    while (*(ptr+length) != '\0') {
        length++;
    }
    return length;
}

void read_line_dynamic(){
    printf("Geben Sie eine Zeichenkette ein: ");
    char test_string[100];
    scanf("%s", test_string);
    printf("Die eingegebene Zeichenkette ist: %s\n", test_string);
    char *ptr=test_string;
    int length=custom_len(ptr);
    char *memory_ptr = malloc(sizeof(char)*length);
    if (memory_ptr == NULL) {
        printf("Fehler beim Allokieren des Speichers\n");
        
    }
    for (int i = 0; i < length; i++) {
        *(memory_ptr+i) = *(ptr+i);
    }
    printf("Die kopierte Zeichenkette ist: %s\n", memory_ptr);
    free(memory_ptr);
    
}
