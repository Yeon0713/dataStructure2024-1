//202110573 윤여헌

#include <stdio.h>
#include <stdlib.h>

int main(){
    double* p1;
    p1 = (double*)malloc(sizeof(double));
    *p1 = 23.92;
    printf("p1: %.2f", *p1);
    free(p1);
    return 0;
}