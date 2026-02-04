#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float zahl1;
float zahl2;
char rechenzeichen;
float ergebnis;

float addition();
float subtraktion();
float multiplikation();
float division();

int main (){
    printf("Erste Kommazahl eingeben:\n");
    scanf ("%f",&zahl1);
    printf("Zweite Kommazahl eingeben:\n");
    scanf ("%f",&zahl2);
    printf("Geben Sie nun den Rechenoperator ein:\n");
    scanf(" %c",&rechenzeichen);
    switch (rechenzeichen){
        case '+':
            ergebnis=addition();
            break;
        case '-':
            ergebnis=subtraktion();
            break;
        case '*':
            ergebnis=multiplikation();
            break;
        case '/':
            if (zahl2 == 0) {
                printf("Fehler: Division durch 0 ist nicht erlaubt.\n");
                return 1;
            }
            ergebnis = division();
            break;
        default:
            printf("Ungültiger Rechenoperator.\n");
            return 1;
    }
    
    printf("Ihr Ergebnis lautet:\n");
    printf("%f",ergebnis);
    return 0;

}
float addition(){
    return zahl1 + zahl2;
}
float subtraktion(){
    return zahl1 - zahl2;
}
float multiplikation(){
    return zahl1 * zahl2;
}
float division(){
    return zahl1 / zahl2;
}