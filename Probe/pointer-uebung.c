#include <stdio.h>

int myNumbers[5]={10,20,30,40,50};
int dif;
int main(){
    int *p1=&myNumbers[1];
    int *p2=&myNumbers[4];
    printf("Erste Adresse: %p",p1);
    printf("\nZweite Adresse: %p",p2);
    dif=p2-p1;
    printf("\nDie Differenz der Adressen beträgt: %d",dif);
    return 0;
}