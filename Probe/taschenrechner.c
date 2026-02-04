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
    if (rechenzeichen=='+'){
        ergebnis=zahl1+zahl2;
    }
    if (rechenzeichen=='*'){
        ergebnis=zahl1*zahl2;
    }
    if (rechenzeichen=='-'){
        ergebnis=zahl1-zahl2;
    }
    if (rechenzeichen=='/'){
        ergebnis=zahl1/zahl2;
    }
    printf("Ihr Ergebnis lautet:\n");
    printf("%f",ergebnis);
    return 0;

}