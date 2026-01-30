#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char status= 0xA7; // Beispielstatuswert
bool Fehler =false;
bool Übertemperatur =false;
bool Unterspannung =false;
int Messwert=0;

int maske_bit_7=0x80; // Beispielmaske für Bit 7
int maske_bit_6=0x40; // Beispielmaske für Bit 6
int maske_bit_5=0x20; // Beispielmaske für Bit 5
int maske_bit_0_3=0x0F; // Beispielmaske für Bits 0 bis 3
int main(void)
{   if (status & maske_bit_7 ==0)
    {
        Fehler=true;
    }
    else
    {
        Fehler=false;
    }
    if (status & maske_bit_6 ==0)
    {
        Übertemperatur=true;
    }
    else
    {
        Übertemperatur=false;
    }
    if (status & maske_bit_5 ==0)
    {
        Unterspannung=true;
    }
    else
    {
        Unterspannung=false;
    }
    Messwert = (status & maske_bit_0_3);
    printf("Fehler: %s\n", Fehler ? "true" : "false");
    printf("Übertemperatur: %s\n", Übertemperatur ? "true" : "false");
    printf("Unterspannung: %s\n", Unterspannung ? "true" : "false");
    printf("Messwert: %d\n", Messwert);
    return 0;
}


