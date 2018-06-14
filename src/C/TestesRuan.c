/*QUESTÃO 06:
Faça uma função que, dado um vetor de reais,
altere todas as ocorrências do número A pelo
número B.*/

#include <stdio.h>

voidfunc2()

int main()
{
	int tam, i, a, b;

	printf("inserir tamanho do vetor:  "); //descobrindo o tamanha do vetor
	scanf("%d", &tam);
	float v[tam];

	for (i = 0; i < tam; i++) //colocando os numeros no vetor
	{
		printf("inserir numero:  ");
		scanf("%f", &v[i]);
	}
	printf("inserir o valor que deseja trocar e o valor que deseja ser colocado:  ");
	scanf("%d %d", &a, &b);
	func1(v, tam);
}
