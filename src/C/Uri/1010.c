#include <stdio.h>

int main()
{
    int codigo1, qtd1, codigo2, qtd2;
    float valorUnd1, valorUnd2;

    scanf(" %i", &codigo1);
    scanf(" %i", &qtd1);
    scanf(" %f", &valorUnd1);

    scanf(" %i", &codigo2);
    scanf(" %i", &qtd2);
    scanf(" %f", &valorUnd2);

    printf("VALOR A PAGAR: R$ %.2f\n", ((qtd1 * valorUnd1) + (qtd2 * valorUnd2)));
}