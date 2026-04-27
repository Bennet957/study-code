#include <stdio.h>

int main() {
    FILE *file;
    int c;

    // Datei zum Lesen öffnen
    file = fopen("testfile.txt", "r");
    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    printf("Inhalt der Datei testfile.txt:\n");
    // Zeichenweise lesen und ausgeben
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
    return 0;
}
