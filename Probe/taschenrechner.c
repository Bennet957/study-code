#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float zahl1;
float zahl2;
char rechenzeichen;
float ergebnis;

int main (){
    printf("Erste Kommazahl eingeben:\n");
    scanf ("%f",&zahl1);
    printf("Zweite Kommazahl eingeben:\n");
    scanf ("%f",&zahl2);
    printf("Geben Sie nun den Rechenoperator ein:\n");
    scanf(" %c",&rechenzeichen);
    switch (rechenzeichen){
        case '+':
            ergebnis=zahl1+zahl2;
            break;
        case '-':
            ergebnis=zahl1-zahl2;
            break;
        case '*':
            ergebnis=zahl1*zahl2;
            break;
        case '/':
            ergebnis=zahl1/zahl2;
            break;
        default:
            printf("Ungültiger Rechenoperator.\n");
            return 1;
    }
    
    printf("Ihr Ergebnis lautet:\n");
    printf("%f",ergebnis);
    return 0;

}