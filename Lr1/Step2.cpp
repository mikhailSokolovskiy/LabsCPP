//
// Created by Mikhail on 12.02.2025.
//
#include <stdio.h>
#define PR(x) printf("x=%p, *x=%d, &x=%p\n", (void*)x, *x, (void*)&x)


int main() {
    char chars[] = {10, 20, 30};
    int ints[] = {100, 200, 300};
    double doubles[] = {1.1, 2.2, 3.3};
    long long longs[] = {10000000000LL, 20000000000LL, 30000000000LL};

    char *pChar = chars;
    int *pInt = ints;
    double *pDouble = doubles;
    long long *pLong = longs;

    printf("Initial addresses:\n");
    printf("char*    = %p\n", (void *) pChar);
    printf("int*     = %p\n", (void *) pInt);
    printf("double*  = %p\n", (void *) pDouble);
    printf("long long* = %p\n", (void *) pLong);

    pChar++;
    pInt++;
    pDouble++;
    pLong++;

    printf("\nAfter increment:\n");
    printf("char*    = %p\n", (void *) pChar);
    printf("int*     = %p\n", (void *) pInt);
    printf("double*  = %p\n", (void *) pDouble);
    printf("long long* = %p\n", (void *) pLong);

    return 0;
}
