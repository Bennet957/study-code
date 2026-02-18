#include <stdio.h>

int main(void) {
    FILE *file = fopen("sensor1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char character[100];
    while (fgets(character,sizeof(character),file)!=NULL){
        printf ("%c",character);
    }
    
    fclose(file);
    return 0;
}
