#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(){

    srand(time(NULL));   // Seed einmal setzen

    const int size_arr = 8;

    int array1[8]={0,0,0,0,0,0,0,0};
    for (int i=2; i<8; i=i+2){
        array1[i]=1;
    }

    int array_result[8]={0,0,0,0,0,0,0,0};

    int *pointer_arr1 = array1;
    int *pointer_arr_result = array_result;

    for (int y=0;y<20;y++){

        // aktuelles Feld ausgeben
        printf("Time %d:",y);
        for (int x=0;x<size_arr;x++){
            printf(" %d ",*(pointer_arr1+x));
        }
        printf("\n");

        // array_result zurücksetzen
        for (int i=0;i<size_arr;i++){
            *(pointer_arr_result+i)=0;
        }

        // Bewegungen berechnen
        for (int k=0;k<size_arr;k++){

            if (*(pointer_arr1+k)==1){

                int direction = rand()%2;
                int new_pos = k;

                if (direction==1){
                    new_pos = k+1;
                } else {
                    new_pos = k-1;
                }

                // Randbedingungen
                if (new_pos<0) new_pos=0;
                if (new_pos>=size_arr) new_pos=size_arr-1;

                // Kollision behandeln
                if (*(pointer_arr_result+new_pos)==1){
                    *(pointer_arr_result+new_pos)=0;
                } else {
                    *(pointer_arr_result+new_pos)=1;
                }
            }
        }

        // nächster Zustand wird aktueller Zustand
        for (int i=0;i<size_arr;i++){
            *(pointer_arr1+i)=*(pointer_arr_result+i);
        }

        sleep(10);
    }

    return 0;
}