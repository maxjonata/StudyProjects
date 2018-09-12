#include <stdio.h>

int main()
{
    int numFuncionario,horasTrabalhadas;
    float valorPorHora;

    scanf(" %i", &numFuncionario);
    scanf(" %i", &horasTrabalhadas);
    scanf(" %f", &valorPorHora);

    printf("NUMBER = %i\n", numFuncionario);
    printf("SALARY = U$ %.2f\n", valorPorHora * horasTrabalhadas);
}