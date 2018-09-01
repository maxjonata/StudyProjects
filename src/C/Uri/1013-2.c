#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,maior;

    scanf(" %i", &A);
    scanf(" %i", &B);
    scanf(" %i", &C);

    maior = (((A+B+abs(A-B))/2) + C + abs(((A+B+abs(A-B))/2) - C) / 2);

    printf("%i eh o maior\n", maior);
}