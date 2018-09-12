#include <stdio.h>

int main()
{
    int A,B,C,maior;

    scanf(" %i", &A);
    scanf(" %i", &B);
    scanf(" %i", &C);

    if(A > B && A > C)
    {
        maior = A;
    }
    else
    {
        if(B > A && B > C)
        {
            maior = B;
        }
        else
        {
            maior = C;
        }
    }

    printf("%i eh o maior\n", maior);
}