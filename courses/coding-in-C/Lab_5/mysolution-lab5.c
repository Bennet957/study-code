#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int size_array=11;
    int array1[size_array]={0,0,0,0,0,0,0,0,0,0};
    array1[1]=1;
    array1[3]=1;
    array1[5]=1;

    int *pointer1=&array1[0];

    int array_temp[size_array]={0,0,0,0,0,0,0,0,0,0};
    return 0;
}
