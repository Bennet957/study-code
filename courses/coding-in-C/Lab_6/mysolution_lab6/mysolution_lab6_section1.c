#include <stdio.h>

int main(void) {
    FILE *file = fopen("sensor1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int character;
    while ((character=fgetc(file)!=EOF)){
        printf ("%c",character);
    }
    
    fclose(file);
    return 0;
}
