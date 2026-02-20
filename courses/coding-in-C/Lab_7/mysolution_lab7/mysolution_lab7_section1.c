#include <stdio.h> 
#include <stdlib.h>

int main(){
    int N;
    printf("Geben sie ihre Zahl ein:");
    scanf("%d",&N);

    int *p = malloc(sizeof(int));

    
    if (p == NULL) {
        printf("Warnung: Speicherzuweisung bei malloc fehlgeschlagen.\n");
        return 1;
    }
    

    *p = N;

    int *np = calloc(N, sizeof(int));

    
    if (np == NULL) {
        printf("Warnung: Speicherzuweisung bei calloc fehlgeschlagen.\n");
        free(p);
        return 1;
    }
    

    for(int c=0;c<N;c++){
        np[c]=c*c;
    }
    
    int *n_2_p=realloc(np,2*N*sizeof(int));

    if (n_2_p == NULL) {
        printf("Fehler bei der Speicherzuweisung.\n");
        free(np);
        free(p);
        return 1;
    }

    np=n_2_p;

    for(int c=0;c<N*2;c++){
        np[c]=c*c;
    }

    for (int c = 0; c < 2*N; c++) {
    printf("Array[%d] = %d\n", c, np[c]);
}

    free(np);
    free(p);

    return 0;
}