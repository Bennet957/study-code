#include <stdio.h>

int main() {

    char cols[] = "ABCDEFGH";

    // Obere Spaltenbeschriftung
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("  %c   ", cols[i]);
    }
    printf("\n");

    for (int row = 8; row >= 1; row--) {

        // Horizontale Trennlinie
        printf("   +");
        for (int i = 0; i < 8; i++) {
            printf("-----+");
        }
        printf("\n");

        // Inhalt der Felder
        printf(" %d |", row);
        for (int col = 0; col < 8; col++) {

            // Schachbrettmuster (abwechselnd ###)
            if ((row + col) % 2 == 0) {
                printf(" ### |");
            } else {
                printf("     |");
            }
        }
        printf(" %d\n", row);
    }

    // Untere Abschlusslinie
    printf("   +");
    for (int i = 0; i < 8; i++) {
        printf("-----+");
    }
    printf("\n");

    // Untere Spaltenbeschriftung
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("  %c   ", cols[i]);
    }
    printf("\n");

    return 0;
}