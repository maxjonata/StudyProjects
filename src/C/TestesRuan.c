#include <stdio.h>
#define CAP 10

void print(int v[], int tam)
{
	int i;
	
	printf("tam = %d \n", tam);
	for(i=0; i<tam; i++)
	{
		printf("%d, ", v[i]);
	}
}

int add(int v[], int *tam)
{
	int contNum=0, num, i, ok=0;
	
	if(*tam>CAP)
	{
		return 0;
	}
	else
	{	
		do 
		{
			printf("inserir numero que deseja add ao vetor:  ");
			scanf("%d", &num);
		
			for(i=0; i<*tam; i++) //validando se N aparece ate N vezes.
			{
				if(num==v[i])
				{
					contNum++;
				}	
			}
			if(contNum<num)
			{
				v[*tam]=num;
				(*tam)++;
				ok++;
			}
			else
			{
				printf("\nQuantidade maxima do numero %d foi alcancada, por favor, digite outro algarismo.\n\n", num);
			}	
		}
		while(ok==0);
	
		for(i=0; i<*tam; i++) //validando se N aparece ate N vezes.
			{
				printf("%d", *tam);
				printf("%d, ", v[i]);

			}
		
		return 1;
	}
}

int main()
{
	int v[100];
	int tam, contNum, i, j, num, operacao, retorno;

	do
	{
		printf("inserir tamanho inicial do vetor(ate %d):  ", (int)CAP);
		scanf("%d", &tam);
		if(tam>CAP)
		{
			printf("tamanho invalido. Por favor, insira um valor ate %d\n", (int)CAP);
		}
	}
	while(tam>CAP);
	
	for(i=0; i<tam; i++)
	{
		contNum=0;
		printf("inserir numero(%d/%d):  ", i+1, tam);
		scanf("%d", &num);
		for(j=0; j<=i; j++)
		{
			if(num==v[j])
			contNum++;
		}
	
		if(contNum<num)
		{
			v[i]=num;
		}
		else
		{
			printf("Quantidade maxima do numero %d foi alcancada, por favor, digite outro algarismo.\n", num);
			i--;
		}
		
	}
	printf("tam = %d\n\n", tam);
	
	
		
	do
	{
		printf("\n");
		printf("_____________________MENU____________________\n\n");
		printf("1 para add um numero ao vetor\n2 para remover todos os numeros do vetor\n3 para remover um elemento que se encontra em uma posicao especifica\n4 para alterar todas as ocorrencias de um valor por outro\n5 para buscar a primeira posicao de um determinado numero\n6 para exibir vetor\n7 para sair");
		printf("\n_____________________________________________\n");
		printf("\nQual operacao o(a) senhor(a) deseja efetuar?:  ");
		scanf("%d", &operacao);
		printf("\n");
		
		if(operacao==1)
		{
				printf("%d", tam);
				retorno=add(v, &tam);
				if(retorno==0)
				{
					printf("o vetor esta cheio, nao e possivel add mais numeros.\n");
				}
		}
		else
			if(operacao==2)
			{
		
			}
			else
				if(operacao==3)
				{
					
				}
				else
					if(operacao==4)
					{
						
					}
					else
						if(operacao==5)
						{
							
						}
						else
							if(operacao==6)
							{
								print(v, tam);
							}
							else
								if(operacao==7)
								{
									
								}
								else
								{
									printf("opcao invalida, tente novamente.");
								}
	}
	while(operacao!=7);
}