#include <stdio.h>

int main(){
    unsigned char sprichwort[100];
    printf("Geben Sie ein Sprichwort ein (maximal 100 Zeichen): ");
    fgets(sprichwort,100,stdin);
    
    // Newline entfernen
    for (int i = 0; sprichwort[i] != '\0'; i++) {
        if (sprichwort[i] == '\n') {
            sprichwort[i] = '\0';
            break;
        }
    }
    
    // Länge des Strings berechnen
    int len = 0;
    for (int i = 0; sprichwort[i] != '\0'; i++) {
        len++;
    }

    unsigned char *p1=&sprichwort[0];
    unsigned char *p100=&sprichwort[len-1];
    int sprichwort_int1=(int)*p1;
    int sprichwort_int100=(int)*p100;

    while (p1 < p100) {
        if (*p100==*p1){
            p100--;
            p1++;
        }
        else {
            printf("Das Sprichwort ist kein Palindrom.");
            return 0;
        }
    }
    
    printf("Das Sprichwort %s ist ein Palindrom.", sprichwort);
    
    
}
