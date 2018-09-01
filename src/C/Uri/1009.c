#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[20];
    double salarioFixo, vendasEfetuadas;

    fflush(stdin);
    gets(nome);
    scanf(" %lf", &salarioFixo);
    scanf(" %lf", &vendasEfetuadas);

    printf("TOTAL = R$ %.2f\n", salarioFixo + (vendasEfetuadas * 0.15));
}