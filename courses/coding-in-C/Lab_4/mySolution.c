#include <stdio.h>

/*
 * Lernziel: String und Pointer verstehen
 * - String ist ein Array von Zeichen
 * - Pointer zeigt auf eine Speicheradresse
 * - Via Pointer kann man String-Inhalte lesen und schreiben
 */

// Funktionsprototyp: Funktion, die den zweiten Buchstaben eines Strings ändert
void change_second_letter(unsigned char *p);

int main(){
    // Aufgabe 1: String mit Inhalte erstellen (Array, nicht Pointer!)
    unsigned char string[]={"Curly bird catches the worm"};
    
    // Aufgabe 2: Pointer auf das Array erstellen (zeigt auf erstes Element)
    unsigned char *p1=&string[0];
    
    // Aufgabe 3: String via Pointer ausgeben (mit Schleife und Dereferenzierung)
    // Hier sehen wir: beide Varianten (Array und Pointer) zeigen auf denselben Speicher
    for (int i=0; i<sizeof(string); i++){
        printf("%c",*p1);  // *p1 = Dereferenzierung: Wert, auf den Pointer zeigt
        p1++;              // Pointer um 1 Byte weiterbewegen (zu nächstem Zeichen)
    }
    printf("\n%s",string);  // Vergleich: Array direkt ausgeben (gibt dasselbe aus!)
    
    // Aufgabe 4: Erste zwei Zeichen via Pointer ändern zu 'E' und 'a'
    // p1 zeigt nun nach der Schleife HINTER den letzten Buchstaben (auf \0)
    // Wir müssen auf den Anfang zurückgehen:
    p1 = &string[0];  // Pointer auf Anfang zurücksetzen
    *p1='E';           // Erster Buchstabe: 'C' -> 'E'
    *(p1+1)='a';       // Zweiter Buchstabe: 'u' -> 'a'
    
    // Unterschied Aufgabe 4 vs Aufgabe 6:
    // - Aufgabe 4: Wir ändern direkt im Array
    // - Aufgabe 6: Wir nutzen eine Funktion (zeigt Wiederverwendbarkeit)
    
    printf("\n--- Aufgabe 7 & 8: Funktion testen ---\n");
    
    // Aufgabe 8: SICHERE Variante - String in modifizierbarem Array erstellen
    // (Nicht String-Literal, da Literale schreibgeschützt sind!)
    unsigned char test[] = "AAtions speak louder than words";
    
    printf("Before: %s\n", (char*)test);
    
    // Aufgabe 5 & 6: Funktion aufrufen, die zweiten Buchstaben zu 'c' ändert
    change_second_letter(test);  // Sicher: test[] ist schreibbar (Stack-Array)
    
    printf("After:  %s\n", (char*)test);
    
    // NICHT tun (Aufgabe 7 - zeigt das Problem):
    // change_second_letter((unsigned char*)"AAtions speak louder than words");
    // Warum nicht? String-Literale sind im schreibgeschützten Speicher -> Absturz!
    
    return 0;
}

/*
 * Aufgabe 5 & 6: Funktion, die den zweiten Buchstaben zu 'c' ändert
 * Parameter: Pointer auf einen String (unsigned char *)
 * Aufgabe 7: Diese Funktion mit einem Literal aufgerufen würde abstürzen!
 * Aufgabe 8: Mit modifizierbarem Array (z.B. auf Stack) funktioniert es.
 */
void change_second_letter(unsigned char *p){
    *(p+1)='c';  // Index 1 (zweiter Buchstabe) zu 'c' ändern
}