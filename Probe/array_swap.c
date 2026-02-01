#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int array_1 [3][3]={{29,38,47},{58,67,76},{99,88,77}};
int array_2 [3][3]={{67,89,54},{18,71,87},{44,55,66}};
int speicher;
int main(void) {
    for (int c=0;c<3;c++){
        for (int c1=0;c1<3;c1++){
            speicher=array_1[c][c1];
            array_1[c][c1]=array_2[c][c1];
            array_2[c][c1]=speicher;
        }
    }
    printf ("Array 1:\n");
    for (int c=0;c<3;c++){
        for (int c1=0;c1<3;c1++){
            printf("%d ",array_1[c][c1]);
        }
        printf("\n");
    }
    printf ("Array 2:\n");
    for (int c=0;c<3;c++){
        for (int c1=0;c1<3;c1++){
            printf("%d ",array_2[c][c1]);
        }
        printf("\n");
    }
}