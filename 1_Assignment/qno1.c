#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {


    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

